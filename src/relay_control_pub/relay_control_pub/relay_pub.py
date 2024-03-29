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
iter_on_off = 0
iter_run = 0
pin_num = 22
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

class RelayControl():
    global new_hum
    global ref_hum

    
    def __init__(self,new_hum,ref_hum):
        global iter_on_off
        global temp
        global pin_num
        if new_hum < ref_hum:
            print('\n현재 온도: {0}\n적정 습도: {1}\n현재 습도: {2}\n가습을 시작합니다.'.format(temp,ref_hum,new_hum))
            GPIO.setmode(GPIO.BCM)
            GPIO.setup(pin_num, GPIO.OUT, initial=False)
            GPIO.setwarnings(False)
            time.sleep(0.2)
            GPIO.output(pin_num, True)
            time.sleep(0.2)
            GPIO.output(pin_num, False)
            GPIO.cleanup()
            time.sleep(2)
            print("가습기 ON")
            iter_on_off = iter_on_off + 1
        else:
            if iter_on_off == 0:
                pass
            else:
                print('\n현재 온도: {0}\n적정 습도: {1}\n현재 습도: {2}\n가습을 종료합니다.'.format(temp,ref_hum,new_hum))
                
                GPIO.setmode(GPIO.BCM)
                GPIO.setup(pin_num, GPIO.OUT, initial=False)
                GPIO.setwarnings(False)
                time.sleep(0.2)
                GPIO.output(pin_num, True)
                time.sleep(0.2)                
                GPIO.output(pin_num, False)
                time.sleep(0.2)
                GPIO.output(pin_num, True)
                time.sleep(0.2)
                GPIO.output(pin_num, False)
                GPIO.cleanup()
                time.sleep(2)
                print("가습기 OFF")
                
                iter_on_off = iter_on_off + 1

def main(args=None):
    rclpy.init(args=args)
    get_DHTdata = GetDHTdata()
    global temp
    global ref_hum
    global old_hum
    global new_hum
    global iter_on_off
    global iter_run
    global pin_num
    try:
        while 1:
            rclpy.spin_once(get_DHTdata)
            if temp >= 24.0:
                ref_hum = 40.0
            elif temp >= 21.0:
                ref_hum = 50.0
            elif temp >= 18.0:
                ref_hum = 60.0
            else:
                ref_hum = 70.0
                 
            if iter_run == 0:
                if new_hum < ref_hum:
                    RelayControl(new_hum, ref_hum)
                    iter_run = iter_run + 1
            else:
                if (old_hum >= ref_hum) is not (new_hum >= ref_hum):
                    RelayControl(new_hum, ref_hum)
                else:
                    pass
            
            old_hum = new_hum
            


    except KeyboardInterrupt:
        if iter_on_off % 2 != 0:
            print("ON상태 가습기 종료")
            GPIO.setmode(GPIO.BCM)
            GPIO.setup(pin_num, GPIO.OUT, initial=False)
            GPIO.setwarnings(False)
            time.sleep(0.2)
            GPIO.output(pin_num, True)
            time.sleep(0.2)                
            GPIO.output(pin_num, False)
            time.sleep(0.2)
            GPIO.output(pin_num, True)
            time.sleep(0.2)
            GPIO.output(pin_num, False)
            GPIO.cleanup()
            GPIO.cleanup()
        else:
            print("가습기 종료")
            GPIO.cleanup()
            get_DHTdata.get_logger().info('Keyboard Interrupt (SIGINT)')
            get_DHTdata.destroy_node()
    finally:
            rclpy.shutdown()

if __name__ == '__main__':
    main()
