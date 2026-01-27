#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

# from aruco_msgs.msg import MarkerArray   # aruco_ros系
from visualization_msgs.msg import Marker
from visualization_msgs.msg import MarkerArray as VizMarkerArray
from ros2_aruco_interfaces.msg import ArucoMarkers
from geometry_msgs.msg import PoseStamped
from rclpy.duration import Duration



import tf2_ros
import tf2_geometry_msgs
import time


class ArucoMarkerMapper(Node):
    def __init__(self):
        super().__init__('aruco_marker_mapper')

        self.sub = self.create_subscription(
            ArucoMarkers,
            '/aruco_markers',
            self.cb,
            10
        )

        self.pub = self.create_publisher(VizMarkerArray, '/marker_map', 10)

        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        time.sleep(2)  # 2秒待つ（必要に応じて調整）

    def cb(self, msg: ArucoMarkers):
        out = VizMarkerArray()

        try:
            tf = self.tf_buffer.lookup_transform(
                'odom', 'camera_link_optical', rclpy.time.Time(), timeout=rclpy.duration.Duration(seconds=1.0)
            )
        except Exception as e:
            self.get_logger().warn(f'TF failed: {e}')
            return

        for i, pose in enumerate(msg.poses):

            ps = PoseStamped()
            ps.header = msg.header
            ps.pose = pose

            map_pose = tf2_geometry_msgs.do_transform_pose(ps, tf)

            marker = Marker()
            marker.header.frame_id = 'odom'
            marker.header.stamp = self.get_clock().now().to_msg()
            marker.ns = 'aruco_map'
            marker.id = int(msg.marker_ids[i])
            marker.type = Marker.SPHERE
            marker.action = Marker.ADD

            marker.pose = map_pose.pose
            marker.scale.x = 0.15
            marker.scale.y = 0.15
            marker.scale.z = 0.15
            marker.color.a = 1.0
            marker.color.r = 1.0

            out.markers.append(marker)

        self.pub.publish(out)



def main():
    rclpy.init()
    node = ArucoMarkerMapper()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
