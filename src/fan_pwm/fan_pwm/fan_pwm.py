import rclpy
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from rclpy.callback_groups import ReentrantCallbackGroup
from std_msgs.msg import Int16
import RPi.GPIO as GPIO

class FanPwmControl(Node):
    
    def __init__(self,channel):
        super().__init__('FanPwm')
        self.channel = channel
        GPIO.setwarnings(False)
        GPIO.setmode(GPIO.BOARD)
        GPIO.setup(self.channel,GPIO.OUT)
        self.pwm = GPIO.PWM(self.channel,2)
        self.pwm.start(10)
        
        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            durability=QoSDurabilityPolicy.VOLATILE)
            
        self.subscribe_pollu_grade = self.create_subscription(
            Int16,
            'pollu_grade',
            self.get_pollu_grade,
            QOS_RKL10V
            )
            
        self.subscribe_gas_grade = self.create_subscription(
            Int16,
            'gas_sensor_pub',
            self.get_gas_grade,
            QOS_RKL10V        
        )
            
    def get_pollu_grade(self,msg):        
        self.pollu_grade = msg.data
        
    def get_gas_grade(self,msg):
        self.gas_grade = msg.data
        
        if self.gas_grade == 2:
            self.pwm.ChangeDutyCycle(100)
            self.get_logger().info('유해가스가 감지되어 팬이 터보모드로 작동합니다.')
        elif self.gas_grade < 2:
          
            if pollu_grade == 0:
                self.pwm.ChangeDutyCycle(30)
                self.get_logger().info('팬이 저속모드 입니다.')
            elif pollu_grade == 1:
                self.pwm.ChangeDutyCycle(50)
                self.get_logger().info('팬이 중속모드 입니다.')
            elif pollu_grade == 2:
                self.pwm.ChangeDutyCycle(80)
                self.get_logger().info('팬이 고속모드 입니다.')
            else:
                self.pwm.ChangeDutyCycle(100)
                self.get_logger().info('팬이 터보모드 입니다.')      


def main(args=None):
    rclpy.init(args=args)
    try:
        channel = 12
        fan_mode = FanPwmControl(channel)
        try:
            rclpy.spin(fan_mode)
        except KeyboardInterrupt:
            fan_mode.get_logger().info('Keyboard Interrupt (SIGINT)')
            GPIO.cleanup()
        finally:
            fan_mode.destroy_node()
    finally:
        GPIO.cleanup()
        rclpy.shutdown()



if __name__ == '__main__':
    main()
