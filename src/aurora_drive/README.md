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

