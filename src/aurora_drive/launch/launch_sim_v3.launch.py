import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


from launch_ros.actions import Node

def generate_launch_description():

    package_name='aurora_drive'

    world = LaunchConfiguration('world')

    declare_world = DeclareLaunchArgument(
        'world',
        default_value=os.path.join(
            get_package_share_directory(package_name),
            'world',
            'aruco.world'   # ← あなたのworldファイル名
        ),
        description='Full path to world file'
    )


    rsp = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory(package_name),'launch','rsp_v2.launch.py'
                )]), launch_arguments={'use_sim_time': 'true', 'use_ros2_control': 'true'}.items()  # ← use_ros2_controlを追加
    )

    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')
                ),
                launch_arguments={'world': world}.items(),
    )


    spawn_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                        arguments=['-topic', 'robot_description',
                                   '-entity', 'my_bot'],
                        output='screen')

    # コントローラを起動
    # diff_drive_spawner = Node(
    #     package="controller_manager",
    #     executable="spawner",
    #     arguments=["diff_drive_controller"],
    # )

    joint_broad_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster"],
    )

    velocity_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["velocity_controller"],
    )

    steering_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["steering_controller"],
    )

    odom_node = Node(
        package='aurora_drive',
        executable='odometry_4ws',
        name='odometry_4ws',
        output='screen',
        parameters=[{'use_sim_time': True}]
    )

    ackermann = Node(
        package='aurora_drive',
        executable='ackermann_sim_controller',
        name='ackermann_sim_controller',
        output='screen',
        parameters=[{'use_sim_time': True}]
    )

    return LaunchDescription([
        declare_world,
        rsp,
        gazebo,
        spawn_entity,
        # diff_drive_spawner,        # ← コメントを外す
        joint_broad_spawner,       # ← コメントを外す
        steering_spawner,          # ← 追加
        velocity_spawner,          # ← 追加
        odom_node,                # ← 追加
        ackermann                 # ← 追加
    ])