#!/usr/bin/env python3
"""
aruco_explorer.py (ROS2版)
ランダムウェイポイントを使ってArucoマーカーを探索
起動時に前進→後進（速度コマンド）→ その後は位置指定で探索
"""
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped, Twist
import random
import math
import yaml
import os
from rclpy.time import Time

class ArucoExplorer(Node):
    def __init__(self):
        super().__init__('aruco_explorer')
        
        # パラメータ
        self.declare_parameter('search_radius', 5.0)
        self.declare_parameter('total_markers', 3)
        self.declare_parameter('map_file', os.path.expanduser('~/aruco_map.yaml'))
        self.declare_parameter('startup_delay', 10.0)  # 起動待ち時間
        self.declare_parameter('forward_duration', 5.0)  # 前進時間（秒）
        self.declare_parameter('backward_duration', 5.0)  # 後進時間（秒）
        self.declare_parameter('move_speed', 0.3)      # 移動速度（m/s）
        
        self.search_radius = self.get_parameter('search_radius').value
        self.total_markers = self.get_parameter('total_markers').value
        self.map_file = self.get_parameter('map_file').value
        startup_delay = self.get_parameter('startup_delay').value
        self.forward_duration = self.get_parameter('forward_duration').value
        self.backward_duration = self.get_parameter('backward_duration').value
        self.move_speed = self.get_parameter('move_speed').value
        
        # Nav2 Action Client
        self.nav_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        
        # ★★★ 速度コマンド送信用Publisher ★★★
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        
        self.current_goal_handle = None  # 現在のNav2ゴールハンドル
        self.exploring = False
        self.initialized = False
        self.moving = False  # 前進後進中フラグ
        self.move_timer = None  # 移動コマンド送信タイマー
        self.phase_timer = None  # フェーズ切り替えタイマー
        
        self.get_logger().info("🔍 Aruco Explorer 起動！")
        self.get_logger().info(f"探索半径: {self.search_radius}m")
        self.get_logger().info(f"⏰ {startup_delay}秒後に探索開始（SLAM安定化待ち）")
        
        # 初期化タイマー
        self.init_timer = self.create_timer(startup_delay, self.initialize_exploration)
        self.check_timer = None
    
    def initialize_exploration(self):
        """探索の初期化"""
        self.get_logger().info("🚀 探索を開始します...")
        
        # 初期化タイマーを停止
        self.init_timer.cancel()
        
        # Nav2が準備できているか確認
        if not self.nav_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().warn("⚠️ Nav2サーバーが応答しません。10秒後に再試行...")
            self.init_timer = self.create_timer(10.0, self.initialize_exploration)
            return
        
        self.initialized = True
        self.get_logger().info("✅ Nav2準備完了！")
        
        # 最初に前進→後進して地図を作成（速度コマンド）
        self.get_logger().info(f"🔄 周囲をスキャン中（前進→後進）...")
        self.start_forward_backward()
    
    def start_forward_backward(self):
        """前進→後進のシーケンスを開始"""
        # ★ Nav2のアクティブなゴールをキャンセル（競合防止）
        if self.current_goal_handle is not None:
            self.get_logger().info("⚠️ Nav2ゴールをキャンセル中...")
            self.current_goal_handle.cancel_goal_async()
            self.current_goal_handle = None
        
        self.moving = True
        self.exploring = False  # Nav2探索は停止
        
        # 前進開始
        self.get_logger().info(f"⬆️ 前��開始: {self.move_speed} m/s × {self.forward_duration}秒")
        self.get_logger().info(f"📏 予想移動距離: {self.move_speed * self.forward_duration:.2f} m")
        
        # 前進コマンドを送信し続けるタイマー（50Hz）
        self.move_timer = self.create_timer(0.02, self.publish_forward_cmd)
        
        # forward_duration秒後に後進に切り替え
        self.phase_timer = self.create_timer(self.forward_duration, self.switch_to_backward)
    
    def publish_forward_cmd(self):
        """前進速度コマンドを送信"""
        twist = Twist()
        twist.linear.x = self.move_speed  # 前進
        twist.linear.y = 0.0
        twist.linear.z = 0.0
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = 0.0  # 回転しない
        
        self.cmd_vel_pub.publish(twist)
    
    def switch_to_backward(self):
        """前進から後進に切り替え"""
        # 前進タイマーを停止
        if self.move_timer:
            self.move_timer.cancel()
            self.move_timer = None
        
        if self.phase_timer:
            self.phase_timer.cancel()
            self.phase_timer = None
        
        # 後進開始
        self.get_logger().info(f"⬇️ 後進開始: {self.move_speed} m/s × {self.backward_duration}秒")
        self.get_logger().info(f"📏 予想移動距離: {self.move_speed * self.backward_duration:.2f} m")
        
        # 後進コマンドを送信し続けるタイマー（50Hz）
        self.move_timer = self.create_timer(0.02, self.publish_backward_cmd)
        
        # backward_duration秒後に停止
        self.phase_timer = self.create_timer(self.backward_duration, self.stop_moving_callback)
    
    def publish_backward_cmd(self):
        """後進速度コマンドを送信"""
        twist = Twist()
        twist.linear.x = -self.move_speed  # 後進（マイナス）
        twist.linear.y = 0.0
        twist.linear.z = 0.0
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = 0.0  # 回転しない
        
        self.cmd_vel_pub.publish(twist)
    
    def stop_moving_callback(self):
        """移動停止タイマーのコールバック"""
        # ★ タイマー自身をキャンセル（1回だけ実行）
        if self.phase_timer:
            self.phase_timer.cancel()
            self.phase_timer = None
        
        self.stop_moving()
    
    def stop_moving(self):
        """移動を停止して位置指定探索に移行"""
        # 移動タイマーを停止
        if self.move_timer:
            self.move_timer.cancel()
            self.move_timer = None
        
        # ★★★ 停止コマンドを送信（重要！）★★★
        twist = Twist()  # 全て0.0
        self.cmd_vel_pub.publish(twist)
        
        # 念のため複数回送信（確実に停止）
        for _ in range(5):
            self.cmd_vel_pub.publish(twist)
        
        self.moving = False
        self.get_logger().info('✅ スキャン完了！')
        self.get_logger().info('📍 位置指定モードに切り替え（Nav2使用）')
        
        # 1秒待ってから通常探索開始
        self.start_exploration_timer = self.create_timer(1.0, self.start_normal_exploration_callback)
    
    def start_normal_exploration_callback(self):
        """通常探索開始タイマーのコールバック"""
        # ★ タイマーをキャンセル（1回だけ実行）
        if self.start_exploration_timer:
            self.start_exploration_timer.cancel()
            self.start_exploration_timer = None
        
        self.start_normal_exploration()
    
    def start_normal_exploration(self):
        """通常の探索を開始（Nav2による位置指定）"""
        self.get_logger().info('🎯 マーカー探索開始（位置指定モード）')
        
        # 定期チェックタイマーを開始
        self.check_timer = self.create_timer(2.0, self.check_and_explore)
        
        # すぐに最初のゴールを設定
        self.go_to_random_waypoint()
        
    def check_and_explore(self):
        """マーカー検出状況を確認して探索続行"""
        if not self.initialized or self.moving:
            return
        
        detected_count = self.get_detected_marker_count()
        
        self.get_logger().info(f"進捗: {detected_count}/{self.total_markers} マーカー発見")
        
        # 全マーカー発見したら終了
        if detected_count >= self.total_markers:
            self.get_logger().info("🎉 全マーカー発見完了！探索終了")
            if self.check_timer:
                self.check_timer.cancel()
            # 最終停止コマンド
            twist = Twist()
            self.cmd_vel_pub.publish(twist)
            return
        
        # 探索中でなければ新しいウェイポイントへ
        if not self.exploring:
            self.go_to_random_waypoint()
    
    def get_detected_marker_count(self):
        """検出済みマーカー数を取得"""
        try:
            with open(self.map_file, 'r') as f:
                data = yaml.safe_load(f)
                return data.get('detected_count', 0)
        except FileNotFoundError:
            return 0
    
    def go_to_random_waypoint(self):
        """ランダムなウェイポイントに移動（Nav2位置指定）"""
    
        # ランダムな極座標を生成
        angle = random.uniform(0, 2 * math.pi)
    
        # 探索範囲を小さくする
        detected_count = self.get_detected_marker_count()
        if detected_count == 0:
            max_radius = min(2.0, self.search_radius)
            self.get_logger().info(f"🔍 初期探索モード（半径{max_radius}m）")
        else:
            max_radius = self.search_radius
    
        radius = random.uniform(0.5, max_radius)
    
        # 直交座標に変換
        x = radius * math.cos(angle)
        y = radius * math.sin(angle)
    
        self.get_logger().info(f"🎯 新しい目標地点: 現在位置から({x:.2f}, {y:.2f}) [相対位置]")
    
        # ゴールを作成
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = PoseStamped()
        goal_msg.pose.header.frame_id = 'base_link'
    
        # ★★★ 修正：タイムスタンプを空に（最新の変換を使用） ★★★
        goal_msg.pose.header.stamp = Time().to_msg()
    
        goal_msg.pose.pose.position.x = x
        goal_msg.pose.pose.position.y = y
        goal_msg.pose.pose.position.z = 0.0
    
        # ランダムな向き
        yaw = random.uniform(0, 2 * math.pi)
        goal_msg.pose.pose.orientation.z = math.sin(yaw / 2.0)
        goal_msg.pose.pose.orientation.w = math.cos(yaw / 2.0)
    
        # Nav2に送信
        self.exploring = True
    
        send_goal_future = self.nav_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )
        send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        """ゴール受付の応答"""
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn('❌ ゴールが拒否されました')
            self.get_logger().warn('💡 次のゴールを試します...')
            self.exploring = False
            self.current_goal_handle = None
            return
    
        self.current_goal_handle = goal_handle
        self.get_logger().info('✅ ゴール受付 [相対位置]')
        self.get_logger().info('🚗 Nav2が経路計画中...')
    
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.goal_result_callback)

    def goal_result_callback(self, future):
        """ゴール到達の結果"""
        try:
            result = future.result().result
            status = future.result().status
        
            self.exploring = False
            self.current_goal_handle = None
        
            if status == 4:  # SUCCEEDED
                self.get_logger().info('✅ ウェイポイント到達成功！')
            elif status == 5:  # CANCELED
                self.get_logger().warn('⚠️ ゴールがキャンセルされました')
            elif status == 6:  # ABORTED
                self.get_logger().warn('❌ ゴール失敗（障害物or到達不可）')
            else:
                self.get_logger().info(f'📍 ゴール終了（ステータス: {status}）')
            
        except Exception as e:
            self.get_logger().error(f'ゴール結果取得エラー: {e}')
            self.exploring = False
            self.current_goal_handle = None
    
    def feedback_callback(self, feedback_msg):
        """ナビゲーション中のフィードバック"""
        pass

def main(args=None):
    rclpy.init(args=args)
    node = ArucoExplorer()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        # 終了時に停止コマンドを送信
        twist = Twist()
        node.cmd_vel_pub.publish(twist)
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()