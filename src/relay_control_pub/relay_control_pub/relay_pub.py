import rclpy
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from rclpy.callback_groups import ReentrantCallbackGroup
from std_msgs.msg import Int16
from std_msgs.msg import Float32
from hanium_interface.msg import GetDht

class HumSubscriber(Node):
    command = 0
    def __init__(self):
        super().__init__('relay_operation')
        self.hum = 0.0
        self.gas = 0
        
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
             
        self.subscribe_gas = self.create_subscription(
             Int16,
             'gas_sensor_pub',
             self.get_gas_value,
             QOS_RKL10V
             )
        
        self.publisher_relay = self.create_publisher(
            Int16,
            'relay_state',
            QOS_RKL10V
        )
        
        self.publisher_gas = self.create_publisher(
            Int16,
            'gas_state',
            QOS_RKL10V
        )
        

    def get_hum_value(self, msg):
        
        self.hum = msg.hum
        self.command = self.commander(self.hum)
        self.get_logger().info('습도 값은 : {0}, 릴레이 조작값은 : {1}'.format(self.hum,self.command))
        
        msg2 = Int16()
        msg2.data = int(self.command)
        self.publisher_relay.publish(msg2)
        if msg2.data == 1: 
            self.get_logger().info("가습을 시작합니다.")
        else:
            self.get_logger().info("가습을 중단합니다.")
        
    def get_gas_value(self, msg):
    
        self.gas = msg.data
        
        msg3 = Int16()
        msg3.data = self.gas
        self.publisher_gas.publish(msg3)
        self.get_logger().info("받은 가스 상태값은 : {0}".format(msg2.data))
        
    def commander(self, hum):
        if 50.0 <= hum:
            self.command = 0
        else:
            self.command = 1
        command = self.command
        return command
         
    
def main(args=None):
    rclpy.init(args=args)
    try:
        sub_hum = HumSubscriber()
        try:
            rclpy.spin(sub_hum)
        except KeyboardInterrupt:
            sub_hum.get_logger().info('Keyboard Interrupt (SIGINT)')
        finally:
            sub_hum.destroy_node()
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
