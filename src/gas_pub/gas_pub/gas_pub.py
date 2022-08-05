import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from std_msgs.msg import Int16
import RPi.GPIO as GPIO

class GasPublisher(Node):
    
    def __init__(self,channel):
        super().__init__('GasPub')
        self.channel = channel
        GPIO.setmode(GPIO.BOARD)
        GPIO.setwarnings(False)
        GPIO.setup(channel, GPIO.IN)
        
        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            durability=QoSDurabilityPolicy.VOLATILE)

        self.pub_gas = self.create_publisher(
            Int16,
            'gas_sensor_pub',
            QOS_RKL10V
            )

        self.timer = self.create_timer(1.0, self.publish_gas_sensor)

    def publish_gas_sensor(self):
        msg = Int16()
        msg.data = self.gpio_on_off(self.channel)
        self.pub_gas.publish(msg)
        self.get_logger().info('가스 감지 상태 : {0}'.format(msg.data))

    def gpio_on_off(self,channel):
        if GPIO.input(channel) <= 1:
            self.state = 0
        else:
            self.state = 1
        return self.state

def main(args=None):
    rclpy.init(args=args)
    try:
        channel = 29
        gas_pub = GasPublisher(channel)
        try:
            rclpy.spin(gas_pub)
        except KeyboardInterrupt:
            gas_pub.get_logger().info('Keyboard Interrupt (SIGINT)')
        finally:
            gas_pub.destroy_node()
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
