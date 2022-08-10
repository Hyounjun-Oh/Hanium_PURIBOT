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

    dust_pub_node = Node(
        package='fine_dust_sensor',
        executable='dust_publisher',
        name='dust_publisher',
        output='screen')
        
    dust_cal_node = Node(
        package='fine_dust_sensor',
        executable='dust_calculator',
        name='dust_calculator',
        output='screen')



    launch_description.add_action(dust_pub_node)
    launch_description.add_action(dust_cal_node)

    return launch_description
