# checkpoint_navigation_node.py
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from geometry_msgs.msg import Twist, Point
from ros2_aruco_interfaces.msg import ArucoMarkers
from aurora_autonav.checkpoint_manager import CheckpointManager
from aurora_autonav.checkpoint_geometry import CheckpointGeometry
from enum import Enum
import math


class NavigationState(Enum):
    """ナビゲーション状態"""
    SEARCHING = 1      # マーカー探索中
    APPROACHING = 2    # チェックポイントに接近中
    PASSING = 3        # 通過中
    PASSED = 4         # 通過完了
    COMPLETED = 5      # 全ミッション完了


class CheckpointNavigationNode(Node):
    """チェックポイント検出・ナビゲーションノード"""
    
    def __init__(self):
        super().__init__('checkpoint_navigation_node')
        
        # パラメータ
        self.declare_parameter('linear_speed', 0.2)  # 直進速度 (m/s)
        self.declare_parameter('angular_speed', 0.3)  # 回転速度 (rad/s)
        self.declare_parameter('approach_distance', 0.10)  # 接近距離 (m)
        self.declare_parameter('pass_distance', 0.30)  # 通過距離 (m)
        self.declare_parameter('target_timeout', 2.0)  # 目標見失いタイムアウト (s)
        
        self.linear_speed = self.get_parameter('linear_speed').value
        self.angular_speed = self.get_parameter('angular_speed').value
        self.approach_distance = self.get_parameter('approach_distance').value
        self.pass_distance = self.get_parameter('pass_distance').value
        self.target_timeout = self.get_parameter('target_timeout').value
        
        # チェックポイントのIDペアを定義
        checkpoint_pairs = [
            {1, 2},
            {3, 4},
            {5, 6},
        ]
        
        # CheckpointManager初期化
        self.cp_manager = CheckpointManager(checkpoint_pairs)
        
        # 幾何学計算
        self.geometry = CheckpointGeometry()
        
        # 状態管理
        self.state = NavigationState.SEARCHING
        self.current_target_cp = None
        
        # 最後に検出されたマーカー情報
        self.last_detected_ids = []
        self.last_aruco_msg = None
        self.last_center = None
        self.last_distance = None
        self.last_angle = None
        
        # ★保存位置ナビゲーション★
        self.target_position = None  # 保存された目標位置（カメラ座標系）
        self.target_last_seen_time = None  # 最後に目標を見た時刻
        
        # 通過制御用
        self.pass_start_distance = None
        self.pass_start_time = None
        self.approach_start_time = None
        
        # QoS設定
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )
        
        # ArUcoマーカー検出結果をサブスクライブ
        self.aruco_sub = self.create_subscription(
            ArucoMarkers,
            '/aruco_markers',
            self.aruco_callback,
            qos_profile
        )
        
        # 速度指令パブリッシャー
        self.cmd_vel_pub = self.create_publisher(
            Twist,
            '/cmd_vel',
            10
        )
        
        # タイマー（10Hz）
        self.timer = self.create_timer(0.1, self.control_loop)
        
        self.get_logger().info('✅ Checkpoint Navigation Node started (with saved position)')
        self.get_logger().info(f'📋 Checkpoint pairs: {checkpoint_pairs}')
        self.get_logger().info(f'⚙️  Linear: {self.linear_speed}m/s, Angular: {self.angular_speed}rad/s')
        self.get_logger().info(f'⚙️  Approach: {self.approach_distance}m, Target timeout: {self.target_timeout}s')
        self.get_logger().info('🔍 State: SEARCHING')
    
    def aruco_callback(self, msg: ArucoMarkers):
        """ArUco検出時のコールバック"""
        
        # メッセージを保存
        self.last_aruco_msg = msg
        
        # 検出されたマーカーIDを取得
        detected_ids = list(msg.marker_ids)
        self.last_detected_ids = detected_ids
        
        if len(detected_ids) == 0:
            self.last_center = None
            self.last_distance = None
            self.last_angle = None
            return
        
        # チェックポイント判定
        cp_id = self.cp_manager.identify_checkpoint(detected_ids)
        
        if cp_id is not None:
            if self.current_target_cp != cp_id:
                # 新しいチェックポイントを発見
                self.current_target_cp = cp_id
                self.state = NavigationState.APPROACHING
                self.approach_start_time = None  # リセット
                self.get_logger().info(f'🎯 Target Checkpoint: CP{cp_id}')
                self.get_logger().info(f'🔄 State: SEARCHING → APPROACHING')
            
            # 中点と法線を計算
            self.calculate_checkpoint_geometry(msg, detected_ids, cp_id)
    
    def calculate_checkpoint_geometry(self, msg: ArucoMarkers, detected_ids: list, cp_id: int):
        """チェックポイントの幾何学情報を計算"""
        
        # チェックポイントのペアを取得
        cp_pair = self.cp_manager.checkpoint_pairs[cp_id - 1]
        
        # ペアのマーカーのインデックスを探す
        indices = []
        for marker_id in cp_pair:
            try:
                idx = detected_ids.index(marker_id)
                indices.append(idx)
            except ValueError:
                pass
        
        if len(indices) != 2:
            return
        
        # 2つのマーカーのPoseを取得
        pose1 = msg.poses[indices[0]]
        pose2 = msg.poses[indices[1]]
        
        # 中点と法線を計算
        center, normal = self.geometry.calculate_center_and_normal(pose1, pose2)
        distance = self.geometry.calculate_distance(center)
        angle = self.geometry.calculate_angle_to_target(center)
        
        # 保存
        self.last_center = center
        self.last_distance = distance
        self.last_angle = angle
        
        # ★目標位置を保存★
        self.target_position = Point(x=center.x, y=center.y, z=center.z)
        self.target_last_seen_time = self.get_clock().now()
        
        self.get_logger().debug(
            f'📐 CP{cp_id}: Distance={distance:.2f}m Angle={angle:.2f}rad'
        )
    
    def control_loop(self):
        """制御ループ（10Hz）"""
        
        if self.state == NavigationState.SEARCHING:
            self.handle_searching()
        
        elif self.state == NavigationState.APPROACHING:
            self.handle_approaching()
        
        elif self.state == NavigationState.PASSING:
            self.handle_passing()
        
        elif self.state == NavigationState.PASSED:
            self.handle_passed()
        
        elif self.state == NavigationState.COMPLETED:
            # 完了状態：停止し続ける
            self.publish_stop()
    
    def handle_searching(self):
        """探索モード：ゆっくり回転してマーカーを探す"""
        twist = Twist()
        twist.linear.x = self.linear_speed * 0.5
        twist.angular.z = self.angular_speed * 0.5  # ゆっくり回転
        self.cmd_vel_pub.publish(twist)
    
    def handle_approaching(self):
        """接近モード：保存位置を使った制御"""
        
        # ★マーカーが見えなくても保存位置を使う★
        if self.last_center is None and self.target_position is None:
            # 一度も見たことがない
            self.get_logger().warn('⚠️  No target position, searching...')
            self.state = NavigationState.SEARCHING
            self.current_target_cp = None
            self.approach_start_time = None
            return
        
        # マーカーが見えなくなってから一定時間経過したらリセット
        if self.last_center is None and self.target_last_seen_time is not None:
            elapsed_since_seen = (self.get_clock().now() - self.target_last_seen_time).nanoseconds / 1e9
            if elapsed_since_seen > self.target_timeout:
                self.get_logger().warn(f'⚠️  Target lost for {elapsed_since_seen:.1f}s, searching...')
                self.state = NavigationState.SEARCHING
                self.current_target_cp = None
                self.target_position = None
                self.approach_start_time = None
                return
        
        # 接近開始時刻を記録
        if self.approach_start_time is None:
            self.approach_start_time = self.get_clock().now()
        
        # タイムアウトチェック（10秒）
        elapsed = (self.get_clock().now() - self.approach_start_time).nanoseconds / 1e9
        if elapsed > 10.0:
            self.get_logger().warn(f'⚠️  Approach timeout ({elapsed:.1f}s), forcing PASSING')
            self.state = NavigationState.PASSING
            self.pass_start_distance = self.last_distance if self.last_distance else 0.1
            self.pass_start_time = self.get_clock().now()
            self.approach_start_time = None
            return
        
        # ★使用する目標位置を決定★
        if self.last_center is not None:
            # マーカーが見えている → 最新の情報を使用
            target_pos = self.last_center
            distance = self.last_distance
            angle = self.last_angle
            using_saved = False
        else:
            # マーカーが見えない → 保存位置を使用
            target_pos = self.target_position
            distance = self.geometry.calculate_distance(target_pos)
            angle = self.geometry.calculate_angle_to_target(target_pos)
            using_saved = True
            
            elapsed_blind = (self.get_clock().now() - self.target_last_seen_time).nanoseconds / 1e9
            self.get_logger().info(
                f'📍 Using saved position (blind for {elapsed_blind:.1f}s)',
                throttle_duration_sec=1.0
            )

        twist = Twist()
        twist.linear.x = self.linear_speed

        # ★2段階制御：カメラ視野角問題の対策★
        far_threshold = 0.25  # 25cm
        
        if distance > far_threshold:
            # === 遠距離モード：角度補正しながら接近 ===
            k_angular = 2.0
            twist.angular.z = -k_angular * angle
            max_angular = self.angular_speed
            twist.angular.z = max(-max_angular, min(max_angular, twist.angular.z))
            mode = "FAR"
        else:
            # === 近距離モード：直進のみ（カメラ視野から外れないように） ===
            twist.angular.z = 0.0
            mode = "NEAR"
        
        # 接近距離チェック
        if distance <= self.approach_distance:
            self.state = NavigationState.PASSING
            self.pass_start_distance = distance
            self.pass_start_time = self.get_clock().now()
            self.approach_start_time = None
            self.get_logger().info(f'🔄 State: APPROACHING → PASSING')
            self.get_logger().info(f'🚀 Starting pass maneuver (dist={distance:.2f}m)')

        self.cmd_vel_pub.publish(twist)

        marker_status = "📷 LIVE" if not using_saved else "📍 SAVED"
        self.get_logger().info(
            f'🎯 {mode} CP{self.current_target_cp} {marker_status}: '
            f'D={distance:.2f}m A={angle:.3f}rad '
            f'v={twist.linear.x:.2f} ω={twist.angular.z:.2f}',
            throttle_duration_sec=0.5
        )
    
    def handle_passing(self):
        """通過モード：3秒間直進"""
        
        # デバッグログ（オプション：削除可）
        self.get_logger().warn('🚨 handle_passing() CALLED')
        
        # 速度指令
        twist = Twist()
        twist.linear.x = self.linear_speed
        twist.angular.z = 0.0
        
        self.get_logger().warn(
            f'🚨 SETTING cmd_vel: linear.x={twist.linear.x:.3f} angular.z={twist.angular.z:.3f}'
        )
        
        self.cmd_vel_pub.publish(twist)
        self.get_logger().warn('🚨 cmd_vel PUBLISHED')
        
        # 経過時間を計算
        elapsed = 0.0
        if self.pass_start_time is not None:
            elapsed = (self.get_clock().now() - self.pass_start_time).nanoseconds / 1e9
        
        # ★タイムアウト判定を最優先に★
        if elapsed > 20.0:
            self.state = NavigationState.PASSED
            self.get_logger().info(f'🔄 State: PASSING → PASSED (timeout {elapsed:.1f}s)')
            self.get_logger().info(f'✅ Checkpoint {self.current_target_cp} passed!')
            self.cp_manager.mark_as_passed(self.current_target_cp)
            return
        
        # 進捗ログ
        if self.target_position is not None and self.pass_start_distance is not None:
            current_dist = self.geometry.calculate_distance(self.target_position)
            distance_traveled = current_dist - self.pass_start_distance
            
            self.get_logger().info(
                f'🚀 PASSING: t={elapsed:.1f}s traveled={distance_traveled:.2f}m/0.30m',
                throttle_duration_sec=0.5
            )
        else:
            self.get_logger().info(
                f'🚀 PASSING: t={elapsed:.1f}s / 3.0s',
                throttle_duration_sec=0.5
            )

    def handle_passed(self):
        """通過完了：次のチェックポイントを探すか終了"""
        
        # まず停止
        self.publish_stop()
        
        # 全チェックポイント通過チェック
        if len(self.cp_manager.passed_checkpoints) >= len(self.cp_manager.checkpoint_pairs):
            self.state = NavigationState.COMPLETED
            self.get_logger().info('🎉 All checkpoints passed! Mission complete!')
            self.get_logger().info('🛑 Robot stopped. Press Ctrl+C to exit.')
            return
        
        # 状態をリセット
        self.state = NavigationState.SEARCHING
        self.current_target_cp = None
        self.last_center = None
        self.pass_start_distance = None
        self.pass_start_time = None
        self.approach_start_time = None
        self.target_position = None  # ★保存位置もリセット★
        self.target_last_seen_time = None
        
        self.get_logger().info(f'🔄 State: PASSED → SEARCHING')
        self.get_logger().info(f'📊 Passed checkpoints: {len(self.cp_manager.passed_checkpoints)}')
    
    def publish_stop(self):
        """停止指令を発行"""
        twist = Twist()
        twist.linear.x = 0.0
        twist.angular.z = 0.0
        self.cmd_vel_pub.publish(twist)


def main(args=None):
    """メイン関数"""
    rclpy.init(args=args)
    node = CheckpointNavigationNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('👋 Keyboard interrupt received')
    except Exception as e:
        node.get_logger().error(f'❌ Exception: {e}')
    finally:
        # 確実に停止指令を送る
        node.get_logger().info('🛑 Sending stop commands...')
        
        # 複数回送信して確実に届ける
        import time
        for i in range(20):
            node.publish_stop()
            time.sleep(0.05)  # 50ms
        
        node.get_logger().info('✅ Stop commands sent (20 times)')
        
        # 後処理
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()