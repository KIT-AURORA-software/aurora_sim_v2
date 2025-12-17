# ~/aurora_sim_v2/src/aurora1/launch/full_navigation. launch.py

import os
from launch import LaunchDescription
from launch. actions import IncludeLaunchDescription, DeclareLaunchArgument, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, SetParameter
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # パッケージディレクトリ
    aurora_drive_dir = get_package_share_directory('aurora_drive')
    slam_toolbox_dir = get_package_share_directory('slam_toolbox')
    nav2_bringup_dir = get_package_share_directory('nav2_bringup')
    
    # パラメータ
    use_sim_time = LaunchConfiguration('use_sim_time')
    
    # 設定ファイル
    joy_params = os.path.join(aurora_drive_dir, 'config', 'joystick.yaml')
    twist_mux_config = os.path.join(aurora_drive_dir, 'config', 'twist_mux.yaml')
    
    return LaunchDescription([
        # Launch引数
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='true',
            description='Use simulation time if true'
        ),
        
        # グローバルパラメータとしてuse_sim_timeを設定
        SetParameter(name='use_sim_time', value=use_sim_time),
        
        # ========== ジョイスティック ==========
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            parameters=[
                joy_params,
                {'use_sim_time': use_sim_time}
            ],
            output='screen'
        ),
        
        Node(
            package='teleop_twist_joy',
            executable='teleop_node',
            name='teleop_node',
            parameters=[
                joy_params,
                {'use_sim_time': use_sim_time}
            ],
            remappings=[('cmd_vel', 'cmd_vel_joy')],
            output='screen'
        ),
        
        # ========== Twist Mux ==========
        Node(
            package='twist_mux',
            executable='twist_mux',
            name='twist_mux',
            output='screen',
            parameters=[
                twist_mux_config,
                {'use_sim_time': use_sim_time}
            ],
            remappings=[
                ('cmd_vel_out', 'diff_cont/cmd_vel_unstamped')
            ]
        ),
        
        # ========== SLAM Toolbox ==========
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(slam_toolbox_dir, 'launch', 'online_async_launch.py')
            ),
            launch_arguments={
                'use_sim_time': 'true'  # 明示的にtrueを設定
            }.items()
        ),
        
        # ========== Nav2 ==========
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(nav2_bringup_dir, 'launch', 'navigation_launch.py')
            ),
            launch_arguments={
                'use_sim_time': 'true'  # 明示的にtrueを設定
            }.items()
        ),
    ])