#!/usr/bin/env python3
import math
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Float64MultiArray

class AckermannSimController(Node):
    def __init__(self):
        super().__init__('ackermann_sim_controller')

        self.declare_parameter('wheelbase', 1.0)
        self.declare_parameter('wheel_radius', 0.15)
        self.declare_parameter('max_steer', math.radians(45))
        self.declare_parameter('cmd_vel_timeout', 0.5)  # ★追加：タイムアウト時間（秒）★

        self.L = self.get_parameter('wheelbase').value
        self.R = self.get_parameter('wheel_radius').value
        self.max_steer = self.get_parameter('max_steer').value
        self.cmd_vel_timeout = self.get_parameter('cmd_vel_timeout').value

        self.steer_filtered = 0.0
        self.filter_alpha = 0.15   # 0.1〜0.3 がちょうど良い
        self.dead_zone = 0.05
        self.max_steer_rate = math.radians(60)  # 1秒で60度まで変化可能
        self.dt = 0.05  # コントロール周期想定

        # ★追加：最後にcmd_velを受信した時刻★
        self.last_cmd_time = self.get_clock().now()

        self.sub = self.create_subscription(
            Twist, '/cmd_vel', self.cb, 10
        )

        self.pub_vel = self.create_publisher(
            Float64MultiArray, '/velocity_controller/commands', 10
        )
        self.pub_steer = self.create_publisher(
            Float64MultiArray, '/steering_controller/commands', 10
        )

        # ★追加：タイマー（20Hz）でタイムアウトをチェック★
        self.timer = self.create_timer(0.05, self.timeout_check)

        self.get_logger().info('AckermannSimController started')
        self.get_logger().info(f'cmd_vel_timeout: {self.cmd_vel_timeout}s')

    def cb(self, msg: Twist):
        # ★追加：受信時刻を更新★
        self.last_cmd_time = self.get_clock().now()

        v = msg.linear.x
        steer_input = msg.angular.z

        # --- ステア入力デッドゾーン ---
        if abs(steer_input) < self.dead_zone:
            steer_input = 0.0

        # --- 角度保持 or 新規入力 ---
        if abs(steer_input) < self.dead_zone:
            steer_target = self.steer_filtered
        else:
            steer_target = steer_input * self.max_steer

        # --- 完全停止 ---
        if abs(v) < 0.05:
           v = 0.0
           steer_target = 0.0

        # --- ステア角制限 ---
        steer_target = max(-self.max_steer, min(self.max_steer, steer_target))

        # --- 一次遅れフィルタ ---
        steer_smooth = (
            self.filter_alpha * steer_target
            + (1.0 - self.filter_alpha) * self.steer_filtered
        )

        # --- ステア速度制限 ---
        delta = steer_smooth - self.steer_filtered
        max_delta = self.max_steer_rate * self.dt
        delta = max(-max_delta, min(max_delta, delta))
        self.steer_filtered += delta

        steer = self.steer_filtered

        # --- 駆動 ---
        w = v / self.R if abs(self.R) > 1e-6 else 0.0

        vel_msg = Float64MultiArray()
        vel_msg.data = [w, w, w, w]

        steer_msg = Float64MultiArray()
        steer_msg.data = [steer, steer, 0.0, 0.0]

        self.pub_vel.publish(vel_msg)
        self.pub_steer.publish(steer_msg)

    def timeout_check(self):
        """★追加：タイムアウトチェック★"""
        elapsed = (self.get_clock().now() - self.last_cmd_time).nanoseconds / 1e9
        
        if elapsed > self.cmd_vel_timeout:
            # タイムアウト：停止指令を送る
            vel_msg = Float64MultiArray()
            vel_msg.data = [0.0, 0.0, 0.0, 0.0]

            steer_msg = Float64MultiArray()
            steer_msg.data = [0.0, 0.0, 0.0, 0.0]

            self.pub_vel.publish(vel_msg)
            self.pub_steer.publish(steer_msg)
            
            # ステアの状態もリセット
            self.steer_filtered = 0.0
            
            self.get_logger().warn(
                f'cmd_vel timeout ({elapsed:.2f}s > {self.cmd_vel_timeout}s), stopping robot',
                throttle_duration_sec=1.0
            )


def main():
    rclpy.init()
    node = AckermannSimController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()