# 使用方法

```
cd ~/aurora_sim_v2
```
でaurora_sim_v2に移動<br>

```
colcon build --symlink-install
source install/setup.bash
```
```
ros2 launch aurora1 launch_sim.launch.py
```
でgazebo起動<br>
別のターミナルに移動し、
```
ros2 run controller_manager spawner joint_state_broadcaster
ros2 run controller_manager spawner diff_drive_controller
ros2 run controller_manager spawner steering_controller
```
でコントロールマネージャー起動。<br>
更に別のターミナルで、
```
ros2 launch aurora1 joystick.launch.py
```
でPS4コントローラ操作できる。<br>

