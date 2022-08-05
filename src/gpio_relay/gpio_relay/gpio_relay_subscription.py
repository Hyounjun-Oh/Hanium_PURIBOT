import rclpy
import time
from rclpy.node import Node
from rclpy.parameter import Parameter
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from std_msgs.msg import Int16
import RPi.GPIO as GPIO

class GpioRelay(Node):
    
    def __init__(self,channel):
        super().__init__('GpioRelay')
        self.relay_state = 0
        global_state = 0
        global_iter = 0
        
        GPIO.setmode(GPIO.BOARD)
        GPIO.setwarnings(False)
        GPIO.setup(channel, GPIO.OUT, initial=GPIO.LOW)
        
        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            durability=QoSDurabilityPolicy.VOLATILE)

        self.get_relay_data = self.create_subscription(
            Int16,
            'relay_state',
            self.get_relay_state,
            QOS_RKL10V,
            )

    def get_relay_state(self,msg2):
        self.state = msg2.data
        self.gpio_on_off(self.state)
        self.get_logger().info('받은 상태값 : {0}'.format(self.state))

    def gpio_on_off(self,state):
        if state == 1:
            if self.global_iter == 0:
                GPIO.output(self.channel, 1)
                
                i = i + 1
            else:
                pass
        else:
            i = 0
            pass

def main(args=None):
    rclpy.init(args=args)
    try:
        channel = 22
        relay = GpioRelay(channel)
        try:
            rclpy.spin(relay)
        except KeyboardInterrupt:
            relay.get_logger().info('Keyboard Interrupt (SIGINT)')
        finally:
            relay.destroy_node()
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
