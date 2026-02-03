#!/usr/bin/env python3
"""
aruco_map_builder.py (ROS2版)
Arucoマーカー（ID 0~8）を検出して地図に記録
"""
import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
import tf2_ros
from visualization_msgs.msg import MarkerArray, Marker
from geometry_msgs.msg import TransformStamped
import yaml
import os

class ArucoMapBuilder(Node):
    def __init__(self):
        super().__init__('aruco_map_builder')
        
        # パラメータ
        self.declare_parameter('total_markers', 3)  # デフォルト3個
        total_markers = self.get_parameter('total_markers').value

        # 検出済みマーカー {id: {'x': x, 'y': y, 'z': z, 'count': n}}
        self.detected_markers = {}
        self.marker_ids = list(range(total_markers))  # 0~(total_markers-1)
        self.total_markers = total_markers
        
        # TF
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        
        # Publisher: 検出済みマーカーを可視化
        self.map_pub = self.create_publisher(
            MarkerArray, 
            '/aruco_map_markers', 
            10
        )
        
        # Timer: 定期的にマーカー位置をチェック (500ms)
        self.timer = self.create_timer(0.5, self.check_markers)
        
        self.get_logger().info(f"Aruco Map Builder起動 - マーカー0~{total_markers-1}を探索中...")
        
    def check_markers(self):
        """全マーカーのTFをチェック"""
        marker_array = MarkerArray()
        
        for marker_id in self.marker_ids:
            frame_name = f'aruco_marker{marker_id}'
            
            try:
                # map座標系への変換を取得
                trans = self.tf_buffer.lookup_transform(
                    'map', 
                    frame_name,
                    rclpy.time.Time(seconds=0),
                    timeout=Duration(seconds=0.1)
                )
                
                pos = trans.transform.translation
                
                # 新規マーカーの場合
                if marker_id not in self.detected_markers:
                    self.detected_markers[marker_id] = {
                        'x': float(pos.x),
                        'y': float(pos.y),
                        'z': float(pos.z),
                        'count': 1
                    }
                    self.get_logger().info(
                        f"🎯 新マーカー検出! ID={marker_id} at ({pos.x:.2f}, {pos.y:.2f})"
                    )
                    self.get_logger().info(
                        f"進捗: {len(self.detected_markers)}/{self.total_markers} 個発見"
                    )
                    self.save_map()
                else:
                    # 既知マーカー: 位置を平均化（精度向上）
                    data = self.detected_markers[marker_id]
                    data['count'] += 1
                    n = data['count']
                    data['x'] = (data['x'] * (n-1) + pos.x) / n
                    data['y'] = (data['y'] * (n-1) + pos.y) / n
                    data['z'] = (data['z'] * (n-1) + pos.z) / n
                
                # RViz可視化用マーカー
                marker = self.create_rviz_marker(
                    marker_id, 
                    self.detected_markers[marker_id]
                )
                marker_array.markers.append(marker)
                
                # テキストラベルも追加
                text_marker = self.create_text_marker(
                    marker_id,
                    self.detected_markers[marker_id]
                )
                marker_array.markers.append(text_marker)
                
            except (tf2_ros.LookupException, 
                    tf2_ros.ConnectivityException, 
                    tf2_ros.ExtrapolationException) as e:
                pass
        
        # 検出済みマーカーを表示
        if marker_array.markers:
            self.map_pub.publish(marker_array)
        
        # 全マーカー発見チェック
        if len(self.detected_markers) == self.total_markers:
            self.get_logger().info(f"✅ 全マーカー（{self.total_markers}個）発見完了！", throttle_duration_sec=5.0)
    
    def create_rviz_marker(self, marker_id, pos_data):
        """RViz表示用マーカー作成"""
        marker = Marker()
        marker.header.frame_id = "map"
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "aruco_map"
        marker.id = marker_id
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        
        marker.pose.position.x = pos_data['x']
        marker.pose.position.y = pos_data['y']
        marker.pose.position.z = pos_data['z']
        marker.pose.orientation.w = 1.0
        
        marker.scale.x = 0.3
        marker.scale.y = 0.3
        marker.scale.z = 0.3
        
        # 緑色
        marker.color.r = 0.0
        marker.color.g = 1.0
        marker.color.b = 0.0
        marker.color.a = 1.0
        
        # lifetime = 0 で永続表示
        marker.lifetime = Duration(seconds=0).to_msg()
        
        return marker
    
    def create_text_marker(self, marker_id, pos_data):
        """テキストラベル作成"""
        text = Marker()
        text.header.frame_id = "map"
        text.header.stamp = self.get_clock().now().to_msg()
        text.ns = "aruco_map_text"
        text.id = marker_id + 100
        text.type = Marker.TEXT_VIEW_FACING
        text.action = Marker.ADD
        
        text.pose.position.x = pos_data['x']
        text.pose.position.y = pos_data['y']
        text.pose.position.z = pos_data['z'] + 0.3
        text.pose.orientation.w = 1.0
        
        text.text = f"ID:{marker_id}"
        text.scale.z = 0.2
        
        text.color.r = 1.0
        text.color.g = 1.0
        text.color.b = 1.0
        text.color.a = 1.0
        
        text.lifetime = Duration(seconds=0).to_msg()
        
        return text
    
    def save_map(self):
        """マーカー地図をYAMLファイルに保存"""
        filepath = os.path.expanduser('~/aruco_map.yaml')
        data = {
            'total_markers': self.total_markers,
            'detected_count': len(self.detected_markers),
            'markers': self.detected_markers
        }
        
        with open(filepath, 'w') as f:
            yaml.dump(data, f, default_flow_style=False)
        
        self.get_logger().info(f"地図保存: {filepath}")

def main(args=None):
    rclpy.init(args=args)
    node = ArucoMapBuilder()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()