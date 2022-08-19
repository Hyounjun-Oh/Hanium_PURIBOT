import rclpy
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from rclpy.callback_groups import ReentrantCallbackGroup
from hanium_interface.msg import Pollu
from std_msgs.msg import Int16

class PolluCalculator(Node):

    def __init__(self):
        super().__init__("pollu_calculator")
        
        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            durability=QoSDurabilityPolicy.VOLATILE)
        
        self.subscribe_gas = self.create_subscription(
            Int16,
            'gas_sensor_pub',
            self.get_gas,
            QOS_RKL10V
        )

        self.subscribe_pollu = self.create_subscription(
            Pollu,
            'pollu_pub',
            self.get_pollu,
            QOS_RKL10V
        )
        
        self.publish_grade = self.create_publisher(
            Int16,
            'pollu_grade',
            QOS_RKL10V
        )
    
    def get_pollu(self, msg):
        
        self.pm10 = msg.pm10
        self.pm2_5 = msg.pm2_5
        self.get_logger().info('\npm10 값은 : {0}\npm2.5 값은 : {1}\n가스탐지 : {2}'.format(self.pm10, self.pm2_5, self.gas))
        
        self.pollu_grade_1(self.pm10, self.pm2_5)
        msg = Int16()
        msg.data = self.pollu_grade
        self.publish_grade.publish(msg)
        self.get_logger().info('\n오염도 값은 : {0}'.format(self.pollu_grade))

    def get_gas(self,msg):
        self.gas = msg.data
        return self.gas
        
        
    def pollu_grade_1(self, result_pm10, result_pm2_5):
        
        if result_pm10 >= 100 :
            self.pollu_grade_pm10 = 10
        elif result_pm10 >= 90 :
            self.pollu_grade_pm10 = 9
        elif result_pm10 >= 80 :
            self.pollu_grade_pm10 = 8
        elif result_pm10 >= 70 :
            self.pollu_grade_pm10 = 7
        elif result_pm10 >= 60 :
            self.pollu_grade_pm10 = 6
        elif result_pm10 >= 50 :
            self.pollu_grade_pm10 = 5
        elif result_pm10 >= 40 :
            self.pollu_grade_pm10 = 4
        elif result_pm10 >= 30 :
            self.pollu_grade_pm10 = 3
        elif result_pm10 >= 20 :
            self.pollu_grade_pm10 = 2
        elif result_pm10 >= 10 :
            self.pollu_grade_pm10 = 1
        elif result_pm10 >= 0 :
            self.pollu_grade_pm10 = 0
            
        if result_pm2_5 >= 50 :
            self.pollu_grade_pm2_5 = 10
        elif result_pm2_5 >= 45 :
            self.pollu_grade_pm2_5 = 9
        elif result_pm2_5 >= 40 :
            self.pollu_grade_pm2_5 = 8
        elif result_pm2_5 >= 35 :
            self.pollu_grade_pm2_5 = 7
        elif result_pm2_5 >= 30 :
            self.pollu_grade_pm2_5 = 6
        elif result_pm2_5 >= 25 :
            self.pollu_grade_pm2_5 = 5
        elif result_pm2_5 >= 20 :
            self.pollu_grade_pm2_5 = 4
        elif result_pm2_5 >= 15 :
            self.pollu_grade_pm2_5 = 3
        elif result_pm2_5 >= 10 :
            self.pollu_grade_pm2_5 = 2
        elif result_pm2_5 >= 5 :
            self.pollu_grade_pm2_5 = 1
        elif result_pm2_5 >= 0 :
            self.pollu_grade_pm2_5 = 0
        
        k = 0.4 #하이퍼파라미터
        
        self.pollu_grade = round(self.pollu_grade_pm2_5 * (1 - k) + self.pollu_grade_pm10 * k) 
        
        if self.pollu_grade > 10:
            self.pollu_grade == 10

        return self.pollu_grade
    
def main(args=None):
    rclpy.init(args=args)
    
    pollu = PolluCalculator()
    try:
        rclpy.spin(pollu)
    except KeyboardInterrupt:
        GPIO.cleanup()
        pollu.get_logger().info('Keyboard Interrupt (SIGINT)')
    finally: 
        pollu.destroy_node()
        GPIO.cleanup()
        rclpy.shutdown() 

if __name__ == '__main__':
    main()
