#!/usr/bin/env python3

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import LogInfo
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import ThisLaunchFileDir
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():

    launch_description = LaunchDescription()

    relay_node = Node(
        package='relay_control_pub',
        executable='relay_pub',
        name='relay_operation',
        output='screen')



    launch_description.add_action(relay_node)

    return launch_description
