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
from launch.actions import IncludeLaunchDescription

def generate_launch_description():
    return LaunchDescription([
        LogInfo(msg=['센서 패키지를 런치 합니다.']),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                [get_package_share_directory('data_export'), '/launch/data_export.launch.py']),
        ),
        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                [get_package_share_directory('dht_sensor'), '/launch/dht_sensor.launch.py']),
        ),
        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                [get_package_share_directory('fan_pwm'), '/launch/fan_control.launch.py']),
        ),
        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                [get_package_share_directory('fine_dust_sensor'), '/launch/dust_sensor.launch.py']),
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                [get_package_share_directory('relay_control_pub'), '/launch/relay_sensor.launch.py']),
        ),
        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                [get_package_share_directory('gas_pub'), '/launch/gas_sensor.launch.py']),
        ),
        
        
    ])


