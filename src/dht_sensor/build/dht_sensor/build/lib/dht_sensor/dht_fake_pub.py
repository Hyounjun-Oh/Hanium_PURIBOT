import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from std_msgs.msg import Float32MultiArray
from hanium_interface.msg import GetDht

class dht_fake(Node):

    def __init__(self):
        super().__init__('dht_fake')
        self.declare_parameter('qos_depth', 10)
        qos_depth = self.get_parameter('qos_depth').value

        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=qos_depth,
            durability=QoSDurabilityPolicy.VOLATILE)

        self.dht_publisher = self.create_publisher(
            GetDht,
            'dht_sensor_fake',
            QOS_RKL10V)

        self.timer = self.create_timer(1.0, self.publish_dht_sensor)

    def publish_dht_sensor(self):
        msg = GetDht()
        msg.hum = 25.0
        msg.temp = 23.5
        self.dht_publisher.publish(msg)
        self.get_logger().info('습도: {0}  온도: {1}'.format(msg.hum,msg.temp))

def main(args=None):

    rclpy.init(args=args)
    try:
        dhtfake = dht_fake()
        try:
            rclpy.spin(dhtfake)
        except KeyboardInterrupt:
            dhtfake.get_logger().info('Keyboard Interrupt (SIGINT)')
        finally:
            dhtfake.destroy_node()
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
