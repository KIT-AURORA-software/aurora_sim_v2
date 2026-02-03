#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray

import serial
import pynmea2

class GpsNode(Node):
    def __init__(self):  # ← これが必要！
        super().__init__("gps_node")

        # pub
        self.gps_pub = self.create_publisher(
            Float64MultiArray,
            '/gps',
            10
        )

        self.port = '/dev/ttyUSB0'
        self.baudrate = 9600
        self.ser = None

        # GPS接続
        try:
            self.ser = serial.Serial(self.port, self.baudrate, timeout=1)
            self.get_logger().info("GPS接続成功")  # ← カンマではなくドット
        except serial.SerialException as e:
            self.get_logger().error(f"GPS接続失敗: {e}")
            return

        # タイマー作成（10Hz = 0.1秒ごと）
        self.timer = self.create_timer(0.1, self.gps_callback)

        # GPSデータ保持
        self.latitude = 0.0
        self.longitude = 0.0

    def gps_callback(self):  # ← msgパラメータは不要
        if self.ser is None or not self.ser.is_open:
            return

        try:
            # while True は使わない！1回だけ読み込む
            line = self.ser.readline().decode('ascii', errors='replace').strip()

            if not line:
                return

            if line.startswith('$GPRMC') or line.startswith('$GNRMC'):
                msg = pynmea2.parse(line)
                if msg.status == 'A':  # 有効なデータのみ
                    self.latitude = msg.latitude if msg.latitude else 0.0  # ← タイポ修正
                    self.longitude = msg.longitude if msg.longitude else 0.0
                    
                    self.get_logger().info(f"時刻: {msg.timestamp}")
                    self.get_logger().info(f"緯度: {self.latitude} {msg.lat_dir}")
                    self.get_logger().info(f"経度: {self.longitude} {msg.lon_dir}")
                    self.get_logger().info(f"速度: {msg.spd_over_grnd} ノット")
                    self.get_logger().info("-" * 50)
                    
                    # パブリッシュ
                    self.publish_gps_data()

            elif line.startswith('$GPGGA') or line.startswith('$GNGGA'):
                msg = pynmea2.parse(line)
                self.get_logger().info(f"衛星数: {msg.num_sats}")
                self.get_logger().info(f"高度: {msg.altitude} {msg.altitude_units}")

        except pynmea2.ParseError:
            pass
        except UnicodeDecodeError:
            pass
        except Exception as e:
            self.get_logger().error(f"エラー: {e}")

    def publish_gps_data(self):
        msg = Float64MultiArray()
        msg.data = [self.latitude, self.longitude]
        self.gps_pub.publish(msg)

    def destroy_node(self):
        """ノード終了時の処理"""
        if self.ser and self.ser.is_open:
            self.ser.close()
            self.get_logger().info("シリアルポートをクローズしました")
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = GpsNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("終了")  # ← タイポ修正
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':  # ← == が必要
    main()