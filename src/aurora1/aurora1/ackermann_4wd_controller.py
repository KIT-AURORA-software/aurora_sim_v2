#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Float64MultiArray
from sensor_msgs.msg import Joy
import math
import time

class Ackermann4WDController(Node):
    def __init__(self):
        super().__init__('ackermann_4wd_controller_v2')
        
        # Publishers
        self.drive_pub = self.create_publisher(
            Twist, 
            '/diff_drive_controller/cmd_vel_unstamped', 
            10
        )
        
        self.steer_pub = self.create_publisher(
            Float64MultiArray, 
            '/steering_controller/commands', 
            10
        )
        
        # Subscriber
        self.joy_sub = self.create_subscription(
            Joy,
            '/joy',
            self.joy_callback,
            10
        )
        
        # Parameters
        # self.max_linear_speed = 1.0  # m/s
        self.max_angular_speed = 1.0  # rad/s
        self.max_steering_angle = 0.7854  # 45度 (π/4)
        self.current_speed = 0.3 #m/s
        self.msgbutton_11 = False #12 → 11
        self.msgbutton_10 = False #11 → 10

        self.get_logger().info('Ackermann 4WD Controller Started')
        self.get_logger().info('Left stick: steering, Right stick: forward/backward')
        self.get_logger().info('RT/LT (triggers): forward/backward alternative')

    def joy_callback(self, msg):
        # ジョイスティック入力を取得
        # 軸の番号はコントローラーによって異なる場合があります
        # 一般的なXboxコントローラーの場合:
        # axes[0]: 左スティック左右 (-1.0 ～ 1.0)
        # axes[1]: 左スティック上下 (-1.0 ～ 1.0) 
        # axes[3]: 右スティック左右 (-1.0 ～ 1.0)
        # axes[4]: 右スティック上下 (-1.0 ～ 1.0)
        # axes[2]: LT (-1.0 ～ 1.0)
        # axes[5]: RT (-1.0 ～ 1.0)
        # buttons[0]: 下
        # buttons[1]: 右
        # buttons[2]: 左
        # buttons[3]: 上
        
        try:
            # ステアリング制御 (左スティック左右)
            steering_input = msg.axes[0] if len(msg.axes) > 0 else 0.0
            left_front_steering_angle = steering_input * self.max_steering_angle  
            right_front_steering_angle = steering_input * self.max_steering_angle
            left_rear_steering_angle = -(steering_input * self.max_steering_angle)
            right_rear_steering_angle = -(steering_input * self.max_steering_angle)


            # # 駆動制御 (右スティック上下 または トリガー)
            # if len(msg.axes) > 4:
            #     # 右スティック上下
            #     linear_input = msg.axes[4]
            # else:
            #     linear_input = 0.0
                
            # # トリガーでの制御も追加 (RT - LT)
            # if len(msg.axes) > 5:
            #     rt = (1.0 - msg.axes[5]) / 2.0  # RT: 0-1
            #     lt = (1.0 - msg.axes[2]) / 2.0  # LT: 0-1
            #     trigger_input = rt - lt
                
            #     # スティックまたはトリガーの大きい方を使用
            #     if abs(trigger_input) > abs(linear_input):
            #         linear_input = trigger_input
            
            # linear_speed = linear_input * self.max_linear_speed

            if msg.buttons[11] and not self.msgbutton_11: #12 → 11
                self.current_speed += 0.1
                
            if msg.buttons[10] and not self.msgbutton_10: #11 → 10
                self.current_speed -= 0.1
                
            linear_speed = self.current_speed

            if msg.axes[4] == 0:
                linear_speed = 0.0
            if msg.axes[4] < 0:
                linear_speed = -linear_speed
            

            # 左斜め移動
            if msg.buttons[1]:
                left_front_steering_angle = self.max_steering_angle
                right_front_steering_angle = self.max_steering_angle
                left_rear_steering_angle = self.max_steering_angle
                right_rear_steering_angle = self.max_steering_angle
            # 右斜め移動
            elif msg.buttons[2]:
                left_front_steering_angle = -self.max_steering_angle
                right_front_steering_angle = -self.max_steering_angle
                left_rear_steering_angle = -self.max_steering_angle
                right_rear_steering_angle = -self.max_steering_angle

            # 旋回
            if msg.buttons[3]:
                left_front_steering_angle = -self.max_steering_angle
                right_front_steering_angle = self.max_steering_angle
                left_rear_steering_angle = self.max_steering_angle
                right_rear_steering_angle = -self.max_steering_angle

            # Twistメッセージを作成・送信
            twist_msg = Twist()
            twist_msg.linear.x = linear_speed
            # twist_msg.linear.y = 0.0
            # twist_msg.linear.z = 0.0
            # twist_msg.angular.x = 0.0
            # twist_msg.angular.y = 0.0
            # twist_msg.angular.z = 0.0
            
            self.drive_pub.publish(twist_msg)
            
            # ステアリングメッセージを作成・送信
            steer_msg = Float64MultiArray()
            steer_msg.data = [left_front_steering_angle, right_front_steering_angle, left_rear_steering_angle, right_rear_steering_angle]

            self.steer_pub.publish(steer_msg)

            # ボタン状態を更新（この部分を追加）
            self.msgbutton_11 = msg.buttons[11]
            self.msgbutton_10 = msg.buttons[10]
            
            # デバッグ情報
            if abs(linear_speed) > 0.01 or abs(left_front_steering_angle) > 0.01 or abs(right_front_steering_angle) > 0.01 or abs(left_rear_steering_angle) > 0.01 or abs(right_rear_steering_angle) > 0.01:
                self.get_logger().info(
                    f'Speed: {linear_speed:.2f} m/s, Left Front Steering: {math.degrees(left_front_steering_angle):.1f}°, Right Front Steering: {math.degrees(right_front_steering_angle):.1f}°, Left Rear Steering: {math.degrees(left_rear_steering_angle):.1f}°, Right Rear Steering: {math.degrees(right_rear_steering_angle):.1f}°'
                )
                
        except IndexError:
            self.get_logger().warn('Controller axes not available')

def main(args=None):
    rclpy.init(args=args)
    
    controller = Ackermann4WDController()
    
    try:
        rclpy.spin(controller)
    except KeyboardInterrupt:
        pass
    
    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()