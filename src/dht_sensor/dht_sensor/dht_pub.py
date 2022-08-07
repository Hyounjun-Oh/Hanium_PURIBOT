import sys
import adafruit_dht as A
import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from hanium_interface.msg import GetDht

class dht_pub(Node): # Node 클래스 상속

    def __init__(self,sensor,pin):
   	
        super().__init__('dht_publisher') 
        self.sensor = sensor
        self.pin = pin
   	
        self.hum, self.temp = A.read_retry(self.sensor,self.pin)
   	
        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            durability=QoSDurabilityPolicy.VOLATILE)
        
        self.dht_publisher = self.create_publisher(
            GetDht,
            'dht_sensor',
            QOS_RKL10V) 
            
        self.timer = self.create_timer(1.0, self.publish_dht)
				# 콜백함수 : n초마다 지정한 콜백함수 실행 


    def publish_dht(self): 
        msg = GetDht() # 퍼블리시할 메시지 
        msg.temp = self.temp
        msg.hum = self.hum
        self.dht_publisher.publish(msg) # 메시지 퍼블리시
        self.get_logger().info('온도: {0} 습도: {1}'.format(msg.temp,msg.hum)) # 콘솔창에 출력 (==print함수) 

def main(args=None):
    rclpy.init(args=args) # 초기화 
    
    dht = dht_pub(11,23) 
    try:
        rclpy.spin(dht) # 콜백함수 실행 
    except KeyboardInterrupt: # 'Ctrl+c'와 같은 인터럽트 시그널 예외 상황 
        dht.get_logger().info('Keyboard Interrupt (SIGINT)')
    finally: 
        dht.destroy_node() # 노드 소멸 
        rclpy.shutdown() # 함수 종료

if __name__ == '__main__':
    main()
