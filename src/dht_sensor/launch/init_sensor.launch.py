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
from launch import LaunchDescription

def generate_launch_description():

    launch_description = LaunchDescription()

    dht_node = Node(
        package='dht_sensor',
        executable='dht_pub',
        name='dht_pub',
        output='screen')

    data_node = Node(
        package='data_export',
        executable='DataExport',
        name='DataExport',
        output='screen')
            
    fan_node = Node(
        package='fan_pwm',
        executable='FanPwm',
        name='FanPwm',
        output='screen')
            
    relay_node = Node(
        package='relay_control_pub',
        executable='relay_operation',
        name='relay_operation',
        output='screen')

    launch_description.add_action(dht_node)
    launch_description.add_action(data_node)
    launch_description.add_action(fan_node)
    launch_description.add_action(relay_node)

    return launch_description
