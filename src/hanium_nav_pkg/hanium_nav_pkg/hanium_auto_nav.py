#! /usr/bin/env python3
# Copyright 2021 Samsung Research America
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from ast import arg
from datetime import date
import time
from time import time
from time import localtime
from time import sleep
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from std_msgs.msg import Int16
from mimetypes import init
import pandas as pd
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
import rclpy
from rclpy.duration import Duration

"""
Basic navigation demo to go to pose.
"""
class algorithm_calculate():
    def __init__(self) -> None:
        self.init_time = 5

    def calculate_index(self,space_n,time_now):
        self.space = space_n
        self.time = time_now
        
        A = self.space * (self.time - self.init_time)
        index = A*self.space
        
        return index
    
    def calculate_time(self,time_input):
        time_convert = time_input *60
        return time_convert

class SpaceNumPublisher(Node):
    
    def __init__(self):
        super().__init__("space_num_pub")
        
        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            durability=QoSDurabilityPolicy.VOLATILE)
    
        self.publisher_space_num = self.create_publisher(
            Int16,
            'space_num',
            QOS_RKL10V
        )

def main():
    rclpy.init()

    space_pub = SpaceNumPublisher()
    navigator = BasicNavigator()
    calculate = algorithm_calculate()
    move_file_name = 'move_data.csv'
    initial_pose_file_name = 'initial_pose.csv'
    stay_file_name = 'stay_'+ str(date.today().year - 2000) + str(date.today().month) + str(date.today().day) + '.csv'
    space_number = 6
    msg = Int16()
    msg.data = 0
    
    stay_data = pd.read_csv('/home/ohj/greenai-ros/move_data/'+stay_file_name)
    position_data = pd.read_csv('/home/ohj/greenai-ros/move_data/'+ move_file_name)
    initial_pose_data = pd.read_csv('/home/ohj/greenai-ros/move_data/'+ initial_pose_file_name)


    # Set initial pose
    initial_pose = PoseStamped()
    initial_pose.header.frame_id = 'map'
    initial_pose.header.stamp = navigator.get_clock().now().to_msg()
    initial_pose.pose.position.x = initial_pose_data.loc[0,'x']
    initial_pose.pose.position.y = initial_pose_data.loc[0,'y']
    initial_pose.pose.orientation.z = initial_pose_data.loc[0,'z']
    initial_pose.pose.orientation.w = initial_pose_data.loc[0,'w']
    navigator.setInitialPose(initial_pose)

    # Activate navigation, if not autostarted. This should be called after setInitialPose()
    # or this will initialize at the origin of the map and update the costmap with bogus readings.
    # If autostart, you should `waitUntilNav2Active()` instead.
    # navigator.lifecycleStartup()

    # Wait for navigation to fully activate, since autostarting nav2
    navigator.waitUntilNav2Active()

    # If desired, you can change or load the map as well
    # navigator.changeMap('/path/to/map.yaml')

    # You may use the navigator to clear or obtain costmaps
    # navigator.clearAllCostmaps()  # also have clearLocalCostmap() and clearGlobalCostmap()
    # global_costmap = navigator.getGlobalCostmap()
    # local_costmap = navigator.getLocalCostmap()
    
    iter_move = 0
    
    for iter_move in range(space_number):
        # Go to first goal pose
        goal_pose = PoseStamped()
        goal_pose.header.frame_id = 'map'
        goal_pose.header.stamp = navigator.get_clock().now().to_msg()
        goal_pose.pose.position.x = position_data.loc[iter_move,'x']
        goal_pose.pose.position.y = position_data.loc[iter_move,'y']
        goal_pose.pose.orientation.w = position_data.loc[iter_move,'w']

        # sanity check a valid path exists
        # path = navigator.getPath(initial_pose, goal_pose)

        navigator.goToPose(goal_pose)

        i = 0
        while not navigator.isTaskComplete():
            ################################################
            #
            # Implement some code here for your application!
            #
            ################################################

            # Do something with the feedback
            i = i + 1
            feedback = navigator.getFeedback()
            if feedback and i % 5 == 0:
                print('Estimated time of arrival: ' + '{0:.0f}'.format(
                    Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9)
                    + ' seconds.')

                # Some navigation timeout to demo cancellation
                if Duration.from_msg(feedback.navigation_time) > Duration(seconds=600.0):
                    navigator.cancelTask()
                    
        print('목표 정화위치 '+ str(iter_move + 1) + '도달')
        msg.data = (iter_move + 1)
        space_pub.publisher_space_num.publish(msg)
        space_pub.get_logger().info('공간번호 퍼블리시: {0}'.format(msg.data))
        
        first = calculate.calculate_index(space_number, localtime(time()).tm_hour)
        stay_time_minute = stay_data.loc[iter_move + first,'stay_time']
        stay_time_second = calculate.calculate_time(stay_time_minute)
        
        #sleep(stay_time_second)
        sleep(3)
        
        iter_move += 1


    # Do something depending on the return code
    result = navigator.getResult()
    if result == TaskResult.SUCCEEDED:
        print('Goal succeeded!')
    elif result == TaskResult.CANCELED:
        print('Goal was canceled!')
    elif result == TaskResult.FAILED:
        print('Goal failed!')
    else:
        print('Goal has an invalid return status!')

    navigator.lifecycleShutdown()

    exit(0)


if __name__ == '__main__':
    main()