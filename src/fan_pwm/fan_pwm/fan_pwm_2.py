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
        GPIO.setmode(GPIO.BCM)
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

    def get_pollu_grade(self,msg):

        self.grade = msg.data
        self.pwm_mode(self.grade)
        self.pwm_info(self.grade)


    def pwm_info(self, grade):
        if grade == 0:
            self.get_logger().info('팬이 저속모드 입니다.')
        elif grade == 1:
            self.get_logger().info('팬이 중속모드 입니다.')
        elif grade == 2:
            self.get_logger().info('팬이 고속모드 입니다.')
        else:
            self.get_logger().info('팬이 터보모드 입니다.')  

    def pwm_mode(self,grade):
        if grade == 0:
            self.pwm.ChangeDutyCycle(10)
        elif grade == 1:
            self.pwm.ChangeDutyCycle(30)
        elif grade == 2:
            self.pwm.ChangeDutyCycle(60)
        else:
            self.pwm.ChangeDutyCycle(90)

def main(args=None):
    rclpy.init(args=args)
    try:
        channel = 18
        fan_mode = FanPwmControl(channel)
        try:
            rclpy.spin(fan_mode)
        except KeyboardInterrupt:
            fan_mode.get_logger().info('Keyboard Interrupt (SIGINT)')
        finally:
            fan_mode.destroy_node()
    finally:
        rclpy.shutdown()



if __name__ == '__main__':
    main()

