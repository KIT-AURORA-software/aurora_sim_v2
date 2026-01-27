# パッケージ説明<br>
自動運転できるようにするためのパッケージ<br>
<br>

## 使用方法<br>
### 地図作成
1. ワーキングスペースに移動しビルドする
```
cd ~/aurora_sim_v2
colcon build
source install/setup.bash
```
2. launch_simを起動する
```
ros2 launch aurora_drive launch_sim.launch.py
```
gazeboが起動したあと左側のInsertのボタンを押して、なんでもいいので障害物などを設置する。<br>
3. 別のターミナルを起動し、
```
ros2 launch slam_toolbox online_async_launch.py   slam_params_file:=/home/fuga1129/aurora_sim_v2/src/aurora_drive/config/slam_toolbox.yaml   use_sim_time:=true
```
を実行する。<br>
4. 更に別のターミナルを起動し、
```
rviz2
```
を起動し、Displaysを色々いじる。<br>
Fixedname : map<br>
Addを押し、BytopicのLaserScan,Odometry,mapをそれぞれダブルクリックしDisplaysに追加する。<br>
![alt text](image-1.png)<br>
5. 更に別のターミナルを起動し
```
ros2 launch aurora_drive joystick.launch.py
```
で、コントローラーを動かしてみるとmapが生成されるのがわかればOK。<br>

### Nav2を利用した自律走行
1. ターミナルで、ワーキングスペースに移動しビルドする。
```
cd ~/aurora_sim_v2
colcon build
source install/setup.bash
```
2. twist_muxノードを起動する。
```
ros2 run twist_mux twist_mux --ros-args   --params-file ./src/aurora_drive/config/twist_mux.yaml   -r cmd_vel_out:=/cmd_vel
```
3. 更に別のターミナルを起動し、別のlaunchファイルを起動する。
```
source install/setup.bash
ros2 launch aurora_drive launch_sim_v2.launch.py
```
4. 更に別のターミナルを起動し、別のlaunchファイルを起動する。
```
source install/setup.bash
ros2 launch aurora_drive joystick_v2.launch.py
```
5. 更に別のターミナルを起動し、別のlaunchファイルを起動する。
```
source install/setup.bash
ros2 launch slam_toolbox online_async_launch.py   slam_params_file:=/home/fuga1129/aurora_sim_v2/src/aurora_drive/config/slam_toolbox.yaml   use_sim_time:=true
```
6. 更に別のターミナルを起動し、別のlaunchファイルを起動する。
```
source install/setup.bash
ros2 launch nav2_bringup navigation_launch.py use_sim_time:=true
```
7. 更に別のターミナルを起動し、rviz2を起動する。
```
rviz2
```
を起動し、Displaysを色々いじる。<br>
Fixedname : map<br>
Addを押し、BytopicのLaserScan,Odometry,mapをそれぞれダブルクリックしDisplaysに追加する。mapは２つ追加する。topic名は<br>
topic: /map<br>
topic: /global_costmap/costmap<br>
としてmapが２つ作成される。<br>
8. 更に別のターミナルを起動し、下のコマンドをコピーして実行する。
```
echo "=== DWB Critic調整 ==="

# 1. RotateToGoalを無効化（最も効果的）
ros2 param set /controller_server FollowPath.critics "Oscillation,BaseObstacle,GoalAlign,PathAlign,PathDist,GoalDist"

# 2. ゴール到達の角度許容範囲を広げる
ros2 param set /controller_server general_goal_checker.yaw_goal_tolerance 1.57

# 3. ゴール到達判定を緩くする
ros2 param set /controller_server general_goal_checker.xy_goal_tolerance 0.3

# 4. サンプリング数を増やす
ros2 param set /controller_server FollowPath.vx_samples 30
ros2 param set /controller_server FollowPath.vtheta_samples 60

# 5. BaseObstacleをさらに緩くする
ros2 param set /controller_server FollowPath.BaseObstacle.scale 0.005

# 6. 経路追従を強く優先
ros2 param set /controller_server FollowPath.PathDist.scale 64.0
ros2 param set /controller_server FollowPath.GoalDist.scale 48.0

# 7. patience を延ばす
ros2 param set /controller_server failure_tolerance 3.0

# 8. コストマップをクリア
ros2 service call /local_costmap/clear_entirely_local_costmap std_srvs/srv/Empty
ros2 service call /global_costmap/clear_entirely_global_costmap std_srvs/srv/Empty

echo "=== 調整完了！新しいゴールを設定してください ==="

```
### Arucoマーカーの位置をRviz2に反映させる場合

9. 8番まで同様に行い更に別のターミナルを開いて
```
ros2 run opencv_ros2 aruco_node_tf --ros-args   -r /image_raw:=/camera/image_raw   -r /camera_info:=/camera/camera_info   -p marker_size:=0.05   -p camera_frame:="camera_link_optical"   -p use_sim_time:=true
```
を実行する。GazeboにArucoマーカーを読み込ませたらTFが出ると思う。<br>
10. 更に別のターミナルを開いて、
```
ros2 run tf2_ros tf2_echo map aruco_marker0 --ros-args -p use_sim_time:=true
```
ターミナルに
```
fuga1129@fuga1129-FMVU8G3WD3:~/aurora_sim_v2$ ros2 run tf2_ros tf2_echo map aruco_marker0 --ros-args -p use_sim_time:=true
[INFO] [1769511915.122098944] [tf2_echo]: Waiting for transform map ->  aruco_marker0: Lookup would require extrapolation into the past.  Requested time 1516.700000 but the earliest data is at time 1516.788000, when looking up transform from frame [aruco_marker0] to frame [map]
At time 1517.700000000
- Translation: [-0.825, 3.002, 0.319]
- Rotation: in Quaternion (xyzw) [0.474, 0.533, 0.521, 0.468]
- Rotation: in RPY (radian) [1.590, 0.004, 1.683]
- Rotation: in RPY (degree) [91.081, 0.250, 96.430]
- Matrix:
 -0.112  0.018  0.994 -0.825
  0.994  0.006  0.112  3.002
 -0.004  1.000 -0.019  0.319
  0.000  0.000  0.000  1.000
At time 1518.600000000
- Translation: [-0.825, 3.002, 0.319]
- Rotation: in Quaternion (xyzw) [0.474, 0.533, 0.521, 0.468]
- Rotation: in RPY (radian) [1.590, 0.004, 1.683]
- Rotation: in RPY (degree) [91.081, 0.250, 96.430]
- Matrix:
 -0.112  0.018  0.994 -0.825
  0.994  0.006  0.112  3.002
 -0.004  1.000 -0.019  0.319
  0.000  0.000  0.000  1.000
At time 1519.600000000
- Translation: [-0.825, 3.002, 0.319]
- Rotation: in Quaternion (xyzw) [0.474, 0.533, 0.521, 0.468]
- Rotation: in RPY (radian) [1.590, 0.004, 1.683]
- Rotation: in RPY (degree) [91.081, 0.250, 96.430]
- Matrix:
 -0.112  0.018  0.994 -0.825
  0.994  0.006  0.112  3.002
 -0.004  1.000 -0.019  0.319
  0.000  0.000  0.000  1.000
At time 1520.600000000
- Translation: [-0.825, 3.002, 0.319]
- Rotation: in Quaternion (xyzw) [0.474, 0.533, 0.521, 0.468]
- Rotation: in RPY (radian) [1.590, 0.004, 1.683]
- Rotation: in RPY (degree) [91.081, 0.250, 96.430]
- Matrix:
 -0.112  0.018  0.994 -0.825
  0.994  0.006  0.112  3.002
 -0.004  1.000 -0.019  0.319
  0.000  0.000  0.000  1.000
```
上のように出ればok<br>
11. 更に別のターミナルで、
```
ros2 run aurora_drive aruco_map_builder --ros-args -p use_sim_time:=true
```
を実行してマーカを読みこんだときに
```
fuga1129@fuga1129-FMVU8G3WD3:~/aurora_sim_v2$ ros2 run aurora_drive aruco_map_builder --ros-args -p use_sim_time:=true
[INFO] [1769511965.365937962] [aruco_map_builder]: Aruco Map Builder起動 - マーカー0~8を探索中...
[INFO] [1769511988.324409123] [aruco_map_builder]: 🎯 新マーカー検出! ID=0 at (0.14, 2.52)
[INFO] [1769511988.325016490] [aruco_map_builder]: 進捗: 1/9 個発見
[INFO] [1769511988.327822254] [aruco_map_builder]: 地図保存: /home/fuga1129/aruco_map.yaml
[INFO] [1769512125.461173866] [aruco_map_builder]: 🎯 新マーカー検出! ID=1 at (-5.87, 1.27)
[INFO] [1769512125.461404175] [aruco_map_builder]: 進捗: 2/9 個発見
[INFO] [1769512125.462363324] [aruco_map_builder]: 地図保存: /home/fuga1129/aruco_map.yaml
[INFO] [1769512153.850336801] [aruco_map_builder]: 🎯 新マーカー検出! ID=2 at (-8.29, -2.53)
[INFO] [1769512153.850898443] [aruco_map_builder]: 進捗: 3/9 個発見
[INFO] [1769512153.852973461] [aruco_map_builder]: 地図保存: /home/fuga1129/aruco_map.yaml
[INFO] [1769512202.426082059] [aruco_map_builder]: 🎯 新マーカー検出! ID=3 at (-12.05, -2.36)
[INFO] [1769512202.426334294] [aruco_map_builder]: 進捗: 4/9 個発見
[INFO] [1769512202.427656402] [aruco_map_builder]: 地図保存: /home/fuga1129/aruco_map.yaml
[INFO] [1769512230.320495348] [aruco_map_builder]: 🎯 新マーカー検出! ID=4 at (-16.02, -0.25)
[INFO] [1769512230.321292833] [aruco_map_builder]: 進捗: 5/9 個発見
```
が出ていればok<br>
RvizでMarkerArrayTopicを追加してiDの場所に球体が出ていればok<br>
![alt text](<Screenshot from 2026-01-27 20-16-53.png>)
このようになっていればok<br>







