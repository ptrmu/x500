import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


mavros_params = [{
    # 'fcu_url': "udp://:14550@:18570",  # simulated
    'fcu_url': "udp://:14550@192.168.1.22:18570",  # running on Pixhawk 5X
}]


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='mavros',
            executable='mavros_node',
            output='screen',
            parameters=mavros_params,
        ),
    ])
