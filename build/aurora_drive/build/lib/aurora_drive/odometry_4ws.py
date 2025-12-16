#!/usr/bin/env python3
import rclpy, math
from rclpy.node import Node
from sensor_msgs.msg import JointState
from nav_msgs.msg import Odometry
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster

class Odometry4WS(Node):
    def __init__(self):
        super().__init__('odometry_4ws')
        self.declare_parameter('wheel_radius', 0.15)
        self.declare_parameter('wheel_separation', 1.0)
        self.declare_parameter('wheelbase', 1.0)
        self.r = self.get_parameter('wheel_radius').value
        self.sep = self.get_parameter('wheel_separation').value
        self.base = self.get_parameter('wheelbase').value
        self.x = self.y = self.theta = 0.0
        self.last = None
        self.last_pos = {}
        self.sub = self.create_subscription(JointState, '/joint_states', self.cb, 50)
        self.pub = self.create_publisher(Odometry, '/odom', 10)
        self.tf = TransformBroadcaster(self)

    def cb(self, msg):
        now = self.get_clock().now()
        if self.last is None:
            self.last = now
            for n in ['left_front_wheel_joint','right_front_wheel_joint','left_back_wheel_joint','right_back_wheel_joint',
                  'left_front_steering_joint','right_front_steering_joint','left_back_steering_joint','right_back_steering_joint']:
                if n in msg.name:
                    i = msg.name.index(n)
                    self.last_pos[n] = msg.position[i]
                else:
                    self.last_pos[n] = 0.0
            return
        dt = (now - self.last).nanoseconds * 1e-9
        if dt == 0.0:
            return

        wnames = ['left_front_wheel_joint','right_front_wheel_joint','left_back_wheel_joint','right_back_wheel_joint']
        snames = [
            'left_front_steering_joint','right_front_steering_joint',
            'left_back_steering_joint','right_back_steering_joint'
        ]
        vels = []
        for n in wnames:
            if n in msg.name:
                i = msg.name.index(n)
                cur = msg.position[i]
                prv = self.last_pos.get(n, cur)
                vels.append((cur - prv) / dt)
                self.last_pos[n] = cur
        steers = []
        for n in snames:
            if n in msg.name:
                i = msg.name.index(n)
                steers.append(msg.position[i])

        if len(vels) < 4 or len(steers) < 2:
            self.last = now
            return

        avg_steer = sum(steers[:2]) / 2
        avg_w = sum(vels) / len(vels)
        v = avg_w * self.r
        if abs(avg_steer) > 1e-3:
            R = self.base / math.tan(avg_steer)
            wz = v / R
        else:
            wz = 0.0

        dth = wz * dt
        dx = v * math.cos(self.theta + dth/2) * dt
        dy = v * math.sin(self.theta + dth/2) * dt

        self.x += dx
        self.y += dy
        self.theta = math.atan2(math.sin(self.theta + dth), math.cos(self.theta + dth))

        odom = Odometry()
        odom.header.stamp = now.to_msg()
        odom.header.frame_id = 'odom'
        odom.child_frame_id = 'base_link'
        odom.pose.pose.position.x = self.x
        odom.pose.pose.position.y = self.y
        odom.pose.pose.orientation.z = math.sin(self.theta/2)
        odom.pose.pose.orientation.w = math.cos(self.theta/2)
        odom.twist.twist.linear.x = v
        odom.twist.twist.angular.z = wz
        self.pub.publish(odom)

        t = TransformStamped()
        t.header.stamp = now.to_msg()
        t.header.frame_id = 'odom'
        t.child_frame_id = 'base_link'
        t.transform.translation.x = self.x
        t.transform.translation.y = self.y
        t.transform.rotation.z = math.sin(self.theta/2)
        t.transform.rotation.w = math.cos(self.theta/2)
        self.tf.sendTransform(t)

        self.last = now

def main():
    rclpy.init()
    node = Odometry4WS()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()