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

        self.L = self.get_parameter('wheelbase').value
        self.R = self.get_parameter('wheel_radius').value
        self.max_steer = self.get_parameter('max_steer').value

        self.steer_filtered = 0.0
        self.filter_alpha = 0.15   # 0.1〜0.3 がちょうど良い
        self.dead_zone = 0.05
        self.max_steer_rate = math.radians(60)  # 1秒で60度まで変化可能
        self.dt = 0.05  # コントロール周期想定

        self.sub = self.create_subscription(
            Twist, '/cmd_vel', self.cb, 10
        )

        self.pub_vel = self.create_publisher(
            Float64MultiArray, '/velocity_controller/commands', 10
        )
        self.pub_steer = self.create_publisher(
            Float64MultiArray, '/steering_controller/commands', 10
        )

        self.get_logger().info('AckermannSimController started')

    def cb(self, msg: Twist):
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
        steer_msg.data = [steer, steer, -steer, -steer]

        self.pub_vel.publish(vel_msg)
        self.pub_steer.publish(steer_msg)




def main():
    rclpy.init()
    node = AckermannSimController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
