import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    joy_params = os.path.join(get_package_share_directory('aurora_drive'), 'config', 'joystick.yaml')

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        
        Node(
        package='joy',
        executable='joy_node',
        name='joy_node',
        parameters=[joy_params, {'use_sim_time': use_sim_time}],
        output='screen'
        ),

        Node(
        package='teleop_twist_joy',
        executable='teleop_node',
        name='teleop_node',
        parameters=[joy_params, {'use_sim_time': use_sim_time}],
        remappings=[('cmd_vel', '/cmd_vel')],
        output='screen'
        ),

    ])