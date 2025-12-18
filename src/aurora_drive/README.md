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
ros2 run twist_mux twist_mux --ros-args   --params-file ./src/aurora_drive/config/twist_mux.yaml   -r cmd_vel_out:=diff_cont/cmd_vel_unstamped
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
fuga1129@fuga1129-FMVU8G3WD3:~/aurora_sim_v2$ echo "=== DWB Critic調整 ==="

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


