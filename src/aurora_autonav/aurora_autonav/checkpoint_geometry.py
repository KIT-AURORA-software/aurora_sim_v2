# checkpoint_geometry.py
import numpy as np
from geometry_msgs.msg import Point, Vector3, Pose
from typing import Tuple
import rclpy



class CheckpointGeometry:
    """チェックポイントの幾何学計算"""
    
    @staticmethod
    def calculate_center_and_normal(
        pose1: Pose,
        pose2: Pose
    ) -> Tuple[Point, Vector3]:
        """
        2つのマーカーから中点と法線ベクトルを計算
        
        Args:
            pose1: マーカー1の姿勢
            pose2: マーカー2の姿勢
        
        Returns:
            center: チェックポイントの中点
            normal: 通過方向（法線ベクトル）
        """
        # マーカー位置を取得（カメラ座標系）
        p1 = np.array([
            pose1.position.x,
            pose1.position.y,
            pose1.position.z
        ])
        p2 = np.array([
            pose2.position.x,
            pose2.position.y,
            pose2.position.z
        ])
        
        # 中点計算
        center = (p1 + p2) / 2.0
        
        # 2点を結ぶベクトル
        line_vector = p2 - p1
        
        # 法線ベクトル計算
        # カメラ座標系では、Z軸が前方（光軸方向）
        # 2点を結ぶ線分に垂直で、カメラに向かう方向を計算
        
        # 方法1: Z軸との外積
        # カメラのZ軸（前方）
        camera_z = np.array([0, 0, 1])
        
        # 線分ベクトルとZ軸の外積 = 線分に垂直なベクトル
        normal = np.cross(line_vector, camera_z)
        
        # 正規化（長さ1に）
        norm = np.linalg.norm(normal)
        if norm > 0:
            normal = normal / norm
        else:
            # 線分がZ軸と平行な場合（稀）
            normal = np.array([1, 0, 0])
        
        # ロボットがいる側（カメラ原点側）に向かうように方向調整
        # カメラ座標系の原点 = ロボットの位置
        robot_to_center = center
        
        # 法線方向とロボット→中点の方向の内積
        # 負なら、法線が逆向き
        if np.dot(normal, robot_to_center) < 0:
            normal = -normal
        
        # Point型に変換
        center_point = Point(x=float(center[0]), y=float(center[1]), z=float(center[2]))
        normal_vector = Vector3(x=float(normal[0]), y=float(normal[1]), z=float(normal[2]))
        
        return center_point, normal_vector
    
    @staticmethod
    def calculate_distance(point: Point) -> float:
        """原点（ロボット）からの距離を計算"""
        return np.sqrt(point.x**2 + point.y**2 + point.z**2)
    
    @staticmethod
    def calculate_angle_to_target(point: Point) -> float:
        """
        目標点への角度を計算（ラジアン）
        カメラ座標系でのヨー角
        """
        return np.arctan2(point.x, point.z)
    
def main(args=None):
    """メイン関数"""
    rclpy.init(args=args)
    node = CheckpointGeometry()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('👋 Shutting down...')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()