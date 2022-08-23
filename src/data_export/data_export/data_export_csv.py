import rclpy
import pandas as pd 
import datetime as dt 
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from rclpy.callback_groups import ReentrantCallbackGroup
from std_msgs.msg import Int16
from std_msgs.msg import Float32
from hanium_interface.msg import GetDht

class DataExport(Node):
    
    def __init__(self):
        super().__init__("data_export")
        
        self.df = pd.DataFrame(columns=['year','month','day', 'hour','local' , 'temp', 'humidity', 'metter'])
        time_now = dt.datetime.now()
        
        self.year = str(time_now.year)
        self.month = str(time_now.month)
        self.day = str(time_now.day)
        self.hour = str(time_now.hour)
        self.temp = 0.0
        self.hum = 0.0
        self.pollu = 0
        
        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            durability=QoSDurabilityPolicy.VOLATILE)

        self.subscribe_hum = self.create_subscription(
             GetDht,
             'dht_sensor',
             self.get_hum_value,
             QOS_RKL10V
             )
             
        self.subscribe_pollu = self.create_subscription(
            Int16,
            'pollu_grade',
            self.get_pollu_value,
            QOS_RKL10V
        )
        
        self.subscribe_space = self.create_subscription(
            Int16,
            'space_num',
            self.get_space_value,
            QOS_RKL10V
        )
        
        
    
    def get_hum_value(self, msg):
        
        self.hum = round(msg.hum,1)
        self.temp = round(msg.temp,1)
        self.get_logger().info('습도값은 : {0}, 온도값은 : {1}'.format(self.hum,self.temp))
        
    def get_pollu_value(self, msg):
    
        self.pollu = msg.data
        self.get_logger().info('오염도 수치는 : {0}'.format(self.pollu))
        
    def get_space_value(self, msg):
    
        self.space = msg.data
        self.df.loc[self.space] = [self.year,self.month,self.day,self.hour, self.space, self.temp, self.hum, self.pollu]
        self.df.to_csv('DataExport'+'_'+ str(self.year) + str(self.month) + str(self.day) +'.csv',index = False,sep=',')
        self.get_logger().info('구역 번호는 : {0}'.format(self.space))
        
def main(args=None):
    rclpy.init(args=args)
    
    try:
        export = DataExport()
        try:
            rclpy.spin(export)
        except KeyboardInterrupt:
            export.get_logger().info('Keyboard Interrupt (SIGINT)')
        finally:
            export.destroy_node()
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
