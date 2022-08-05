import rclpy
import sys
import Adafruit_DHT as A
import RPi.GPIO as GPIO
from rclpy.node import Node
from rclpy.qos import QoSProfile # 퍼블리셔의 QoS 설정 
from std_msgs.msg import Float32 # 퍼블리시 메시지 타입 

class dht_pub(Node): # Node 클래스 상속

    def __init__(self,sensor,pin):
   	
        super().__init__('dht_publisher') 
        self.sensor = sensor
        self.pin = pin
   	
        self.hum, self.temp = A.read_retry(self.sensor,self.pin)
   	
        qos_profile = QoSProfile(depth=10) # 퍼블리시할 데이터를 버퍼에 10개까지 저장
        self.dht_publisher = self.create_publisher(Float32, 'data', qos_profile)
				# 퍼블리셔 설정 : 토픽 메시지 타입, 이름, QoS 설정 
        self.timer = self.create_timer(1, self.publish_dht)
				# 콜백함수 : n초마다 지정한 콜백함수 실행 
        self.count = 0
        
        
        

    def publish_dht(self): 
        msg = Float32() # 퍼블리시할 메시지 
        msg.temp = self.temp
        msg.hum = self.hum
        self.dht_publisher.publish(msg) # 메시지 퍼블리시
        self.get_logger().info('Published temp: {0} Published hum: {0}'.format(msg.temp,msg.hum)) # 콘솔창에 출력 (==print함수) 
        self.count += 1

def main(args=None):
    rclpy.init(args=args) # 초기화 
    node = dht_pub(11,23) 
    try:
        rclpy.spin(node) # 콜백함수 실행 
    except KeyboardInterrupt: # 'Ctrl+c'와 같은 인터럽트 시그널 예외 상황 
        node.get_logger().info('Keyboard Interrupt (SIGINT)')
    finally: 
        node.destroy_node() # 노드 소멸 
        rclpy.shutdown() # 함수 종료

if __name__ == '__main__':
    main()
