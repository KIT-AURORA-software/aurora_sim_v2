#!/usr/bin/env python3
import os
import csv

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from cv_bridge import CvBridge

import cv2


def load_aruco_words(csv_filename: str) -> dict[int, str]:
    # この.pyと同じ場所のCSVを読む（VSCode/Gazeboでもズレにくい）
    base_dir = os.path.dirname(os.path.abspath(__file__))
    csv_path = os.path.join(base_dir, csv_filename)

    aruco_dict: dict[int, str] = {}
    with open(csv_path, "r", encoding="utf-8", newline="") as f:
        reader = csv.DictReader(f, skipinitialspace=True)
        for row in reader:
            aruco_id = int(row["aruco_id"])
            word = row["word"]
            aruco_dict[aruco_id] = word

    return aruco_dict


class ArucoWordNode(Node):
    def __init__(self):
        super().__init__("aruco_word_node")

        # 変更しやすいようにパラメータ化（トピックは後でリマップでもOK）
        self.declare_parameter("image_topic", "/camera/image_raw")
        self.declare_parameter("csv_file", "model.csv")
        self.declare_parameter("dict_name", "DICT_4X4_50")

        image_topic = self.get_parameter("image_topic").get_parameter_value().string_value
        csv_file = self.get_parameter("csv_file").get_parameter_value().string_value
        dict_name = self.get_parameter("dict_name").get_parameter_value().string_value

        self.aruco_map = load_aruco_words(csv_file)
        self.get_logger().info(f"対応表: {self.aruco_map}")

        # OpenCV ArUco（旧API対応）
        aruco_module = cv2.aruco
        dict_id = getattr(aruco_module, dict_name, aruco_module.DICT_4X4_50)
        self.aruco_dict = aruco_module.getPredefinedDictionary(dict_id)
        self.parameters = aruco_module.DetectorParameters_create()

        self.bridge = CvBridge()

        self.sub = self.create_subscription(Image, image_topic, self.cb_image, 10)
        self.get_logger().info(f"Subscribe: {image_topic}")

        self.last_ids = set()  # 同じIDを毎フレーム出し続けない用（好みで消してOK）

    def cb_image(self, msg: Image):
        # ROS Image -> OpenCV画像
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        except Exception as e:
            self.get_logger().error(f"cv_bridge convert failed: {e}")
            return

        corners, ids, _ = cv2.aruco.detectMarkers(
            frame, self.aruco_dict, parameters=self.parameters
        )

        if ids is None:
            self.last_ids.clear()
            return

        detected = set(int(x) for x in ids.flatten())

        # 新しく見えたIDだけ出力（毎フレーム出したいならこのifブロックごと消してOK）
        new_ids = detected - self.last_ids
        self.last_ids = detected

        for marker_id in sorted(new_ids):
            word = self.aruco_map.get(marker_id, "unknown")
            self.get_logger().info(f"Detected ID={marker_id} -> word='{word}'")


def main():
    rclpy.init()
    node = ArucoWordNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()