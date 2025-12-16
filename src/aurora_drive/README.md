# パッケージ説明<br>
自動運転できるようにするためのパッケージ<br>
<br>

## 使用方法
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
![alt text](image-1.png)
5. 更に別のターミナルを起動し
```
ros2 launch aurora_drive joystick.launch.py
```
で、コントローラーを動かしてみるとmapが生成されるのがわかればOK。

