# checkpoint_navigation_node.py
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from geometry_msgs.msg import Twist
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


class CheckpointNavigationNode(Node):
    """チェックポイント検出・ナビゲーションノード"""
    
    def __init__(self):
        super().__init__('checkpoint_navigation_node')
        
        # パラメータ
        self.declare_parameter('linear_speed', 0.2)  # 直進速度 (m/s)
        self.declare_parameter('angular_speed', 0.3)  # 回転速度 (rad/s)
        self.declare_parameter('approach_distance', 0.10)  # 接近距離 (m) ★修正★
        self.declare_parameter('pass_distance', 0.30)  # 通過距離 (m) ★修正★
        
        self.linear_speed = self.get_parameter('linear_speed').value
        self.angular_speed = self.get_parameter('angular_speed').value
        self.approach_distance = self.get_parameter('approach_distance').value
        self.pass_distance = self.get_parameter('pass_distance').value
        
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
        
        # 通過制御用
        self.pass_start_distance = None
        self.pass_start_time = None  # ★追加★
        
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
        
        self.get_logger().info('✅ Checkpoint Navigation Node started')
        self.get_logger().info(f'📋 Checkpoint pairs: {checkpoint_pairs}')
        self.get_logger().info(f'⚙️  Linear: {self.linear_speed}m/s, Angular: {self.angular_speed}rad/s')
        self.get_logger().info(f'⚙️  Approach: {self.approach_distance}m, Pass timeout: 2.0s')
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
    
    def handle_searching(self):
        """探索モード：ゆっくり回転してマーカーを探す"""
        twist = Twist()
        twist.linear.x = self.linear_speed * 0.5
        twist.angular.z = self.angular_speed * 0.5  # ゆっくり回転
        self.cmd_vel_pub.publish(twist)
    
    def handle_approaching(self):
        """接近モード：比例制御で滑らかに移動"""
    
        if self.last_center is None or self.last_distance is None or self.last_angle is None:
            self.get_logger().warn('⚠️  Lost markers, searching...')
            self.state = NavigationState.SEARCHING
            self.current_target_cp = None
            return
    
        twist = Twist()
    
        # 比例制御ゲイン
        k_angular = 2.0  # 角度補正の強さ（大きいほど強く回転）
    
        # 常に前進
        twist.linear.x = self.linear_speed

        # 角度に比例した回転速度
        twist.angular.z = -k_angular * self.last_angle
    
        # 速度制限
        max_angular = self.angular_speed
        twist.angular.z = max(-max_angular, min(max_angular, twist.angular.z))
        
        # 接近距離チェック
        if self.last_distance < self.approach_distance:
            self.state = NavigationState.PASSING
            self.pass_start_distance = self.last_distance
            self.pass_start_time = self.get_clock().now()  # ★追加★
            self.get_logger().info(f'🔄 State: APPROACHING → PASSING')
            self.get_logger().info(f'🚀 Starting pass maneuver (start_dist={self.pass_start_distance:.2f}m)')
    
        self.cmd_vel_pub.publish(twist)
    
        self.get_logger().info(
            f'🎯 APPROACHING CP{self.current_target_cp}: '
            f'Dist={self.last_distance:.2f}m Angle={self.last_angle:.3f}rad '
            f'Cmd: v={twist.linear.x:.2f} ω={twist.angular.z:.2f}',
            throttle_duration_sec=0.5
        )
    
    def handle_passing(self):
        """通過モード：一定速度で直進"""
        
        twist = Twist()
        twist.linear.x = self.linear_speed
        twist.angular.z = 0.0
        self.cmd_vel_pub.publish(twist)
        
        # ★通過判定1: マーカーを見失った★
        if self.last_center is None:
            self.state = NavigationState.PASSED
            self.get_logger().info(f'🔄 State: PASSING → PASSED (lost markers)')
            self.get_logger().info(f'✅ Checkpoint {self.current_target_cp} passed!')
            self.cp_manager.mark_as_passed(self.current_target_cp)
            return
        
        # ★通過判定2: 距離が増加した（通り過ぎた）★
        if self.pass_start_distance is not None and self.last_distance is not None:
            distance_change = self.last_distance - self.pass_start_distance
            if distance_change > 0.05:  # 5cm以上遠ざかった
                self.state = NavigationState.PASSED
                self.get_logger().info(
                    f'🔄 State: PASSING → PASSED (distance increased by {distance_change:.2f}m)'
                )
                self.get_logger().info(f'✅ Checkpoint {self.current_target_cp} passed!')
                self.cp_manager.mark_as_passed(self.current_target_cp)
                return
        
        # ★通過判定3: タイムアウト（2秒以上経過）★
        if self.pass_start_time is not None:
            elapsed = (self.get_clock().now() - self.pass_start_time).nanoseconds / 1e9
            if elapsed > 2.0:
                self.state = NavigationState.PASSED
                self.get_logger().info(f'🔄 State: PASSING → PASSED (timeout {elapsed:.1f}s)')
                self.get_logger().info(f'✅ Checkpoint {self.current_target_cp} passed!')
                self.cp_manager.mark_as_passed(self.current_target_cp)
                return
        
        # 現在の状態をログ
        elapsed = 0.0
        if self.pass_start_time is not None:
            elapsed = (self.get_clock().now() - self.pass_start_time).nanoseconds / 1e9
        
        dist_info = ""
        if self.last_distance is not None and self.pass_start_distance is not None:
            dist_info = f" dist={self.last_distance:.2f}m (Δ{self.last_distance - self.pass_start_distance:+.2f}m)"
        
        self.get_logger().info(
            f'🚀 PASSING CP{self.current_target_cp}: t={elapsed:.1f}s{dist_info}',
            throttle_duration_sec=0.5
        )
    
    def handle_passed(self):
        """通過完了：次のチェックポイントを探す"""
        
        # 停止
        twist = Twist()
        twist.linear.x = 0.0
        twist.angular.z = 0.0
        self.cmd_vel_pub.publish(twist)
        
        # 状態をリセット
        self.state = NavigationState.SEARCHING
        self.current_target_cp = None
        self.last_center = None
        self.pass_start_distance = None
        self.pass_start_time = None
        
        self.get_logger().info(f'🔄 State: PASSED → SEARCHING')
        self.get_logger().info(f'📊 Passed checkpoints: {len(self.cp_manager.passed_checkpoints)}')
        
        # 全チェックポイント通過チェック
        if len(self.cp_manager.passed_checkpoints) >= len(self.cp_manager.checkpoint_pairs):
            self.get_logger().info('🎉 All checkpoints passed! Mission complete!')
    
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
        node.get_logger().info('👋 Shutting down...')
        node.publish_stop()
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()