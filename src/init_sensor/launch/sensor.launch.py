from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import LogInfo


def generate_launch_description():
    return LaunchDescription([
        LogInfo(msg=['센서를 불러옵니다...']),
    
        Node(
            package='dht_sensor',
            name='dht_fake_pub',
            executable='dht_fake_pub'  
        ),
        
        Node(
            package='gas_pub',
            name='GasFakePub',
            executable='GasFakePub'
        )
    ])
    
