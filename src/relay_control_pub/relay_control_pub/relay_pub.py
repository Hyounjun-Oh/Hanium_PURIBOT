import rclpy
import RPi.GPIO as GPIO
import time
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from hanium_interface.msg import GetDht

temp = 0.0
ref_hum = 0.0
old_hum = 0.0
new_hum = 0.0

class GetDHTdata(Node):
    
    def __init__(self):
        super().__init__('get_DHTdata')

        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            durability=QoSDurabilityPolicy.VOLATILE)
     
        self.subscribe_dht = self.create_subscription(
             GetDht,
             'dht_sensor',
             self.get_dht_data,
             QOS_RKL10V
             )
        
    def get_dht_data(self, msg):
        global new_hum
        global temp
        new_hum = msg.hum
        temp = msg.temp
        self.get_logger().info('데이터 수신 완료')

class RelayControl():
    global new_hum
    global ref_hum
    def __init__(self,new_hum,ref_hum):

        if new_hum >= ref_hum:
            GPIO.setmode(GPIO.BCM)
            GPIO.setup(19, GPIO.OUT, initial=False)
            GPIO.setwarnings(False)

            print('가습기 가동 중지')
            GPIO.output(19, True)
            time.sleep(3)
            GPIO.output(19, False)
            GPIO.cleanup()
        else:
            GPIO.setmode(GPIO.BCM)
            GPIO.setup(19, GPIO.OUT, initial=False)
            GPIO.setwarnings(False)

            print('가습기 작동을 시작합니다.')
            GPIO.output(19, True)
            time.sleep(3)
            GPIO.output(19, False)
            GPIO.cleanup()

def main(args=None):
    rclpy.init(args=args)
    get_DHTdata = GetDHTdata()
    global temp
    global ref_hum
    global old_hum
    global new_hum
    try:
        while 1:
            rclpy.spin_once(get_DHTdata)
            print('if문 진입')
            print(temp)
            print(new_hum)
            if temp >= 24.0:
                ref_hum = 40.0
            elif temp >= 21.0:
                ref_hum = 50.0
            elif temp >= 18.0:
                ref_hum = 60.0
            else:
                ref_hum = 70.0
            print(ref_hum)
            print('기준 습도 if문 시작')
            if (old_hum >= ref_hum) is not (new_hum >= ref_hum):
                 print('릴레이 작동')
                 RelayControl(new_hum, ref_hum)
            else:
                 print('패스')
                 pass
            old_hum = new_hum
            print('반복 종료')

    except KeyboardInterrupt:
        get_DHTdata.get_logger().info('Keyboard Interrupt (SIGINT)')
        get_DHTdata.destroy_node()
        GPIO.cleanup()
    finally:
        get_DHTdata.destroy_node()
        rclpy.shutdown()
        GPIO.cleanup()
        

if __name__ == '__main__':
    main()
