import rclpy
import RPi.GPIO as GPIO
import time
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from rclpy.callback_groups import ReentrantCallbackGroup
from hanium_interface.msg import GetDht

class RelayControl(Node):

    def __init__(self):
        super().__init__('relay_operation')
        self.hum = 0.0
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(19, GPIO.OUT, initial=GPIO.LOW)
        GPIO.setwarnings(False)

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

    def get_hum_value(self, msg):
        
        self.hum = msg.hum
        self.command = self.commander(self.hum)
        self.get_logger().info('습도 값은 : {0}, 릴레이 조작값은 : {1}'.format(self.hum,self.command))
        
        if self.command == 1: 
            self.get_logger().info("가습을 시작합니다.")
            GPIO.setmode(GPIO.BCM)
            GPIO.setup(19, GPIO.OUT, initial=GPIO.LOW)
            GPIO.setwarnings(False)
            GPIO.output(19, GPIO.LOW)
        else:
            self.get_logger().info("가습을 중단합니다.")
            GPIO.cleanup()

    def commander(self, hum):
        if 50.0 <= hum:
            self.command = 0
        else:
            self.command = 1
        return self.command
         
    
def main(args=None):
    rclpy.init(args=args)

    try:
        relay_control = RelayControl()
        try:
            rclpy.spin(relay_control)
        except KeyboardInterrupt:
            relay_control.get_logger().info('Keyboard Interrupt (SIGINT)')
            GPIO.cleanup()
        finally:
            relay_control.destroy_node()
    finally:
        rclpy.shutdown()
        GPIO.cleanup()


if __name__ == '__main__':
    main()
