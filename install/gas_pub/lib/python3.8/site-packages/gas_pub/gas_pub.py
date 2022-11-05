import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from std_msgs.msg import Int16
import serial

class GasPublisher(Node):
    
    def __init__(self,read_data):
        super().__init__('GasPub')  
        self.read_data = read_data   
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
        msg.data = self.read_data
        self.pub_gas.publish(msg)
        self.get_logger().info('가스 감지 상태 : {0}'.format(msg.data))



def main(args=None):
    rclpy.init(args=args)
    try:
        read_data = 0
        gas_pub = GasPublisher(read_data)
        while 1:
            ser = serial.Serial("/dev/ttyACM0", 9600, timeout=1)   
            res = ser.readline()
            
            if ser.readable():
                read_data = int(ser.readline().decode())
                gas_pub = GasPublisher(read_data)                    
                rclpy.spin_once(gas_pub)
            else:
                pass         
    except KeyboardInterrupt:
        gas_pub.get_logger().info('Keyboard Interrupt (SIGINT)')
    finally:
        gas_pub.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
