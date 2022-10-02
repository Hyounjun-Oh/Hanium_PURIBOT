import rclpy
import RPi.GPIO as GPIO
import time
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from hanium_interface.msg import GetDht

class GetDHTdata(Node):
    global new_hum
    global temp
    
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
         new_hum = msg.hum
         temp = msg.temp
             
class RelayControl(Node):
    global new_hum
    global ref_hum
    
    def __init__(self,new_hum,ref_hum):

        
        if new_hum >= ref_hum:
            self.get_logger.info('가습기 작동을 중단합니다.')
            GPIO.output(19, GPIO.HIGH)
            time.sleep(3)
            GPIO.output(19, GPIO.LOW)         
        else:
            self.get_logger.info('가습기 작동을 시작합니다.')
            GPIO.output(19, GPIO.HIGH)
            time.sleep(3)
            GPIO.output(19, GPIO.LOW)
         
    
def main(args=None):
    rclpy.init(args=args)
    get_DHTdata = GetDHTdata()
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(19, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setwarnings(False)
    
    temp = 0.0
    ref_hum = 0.0
    old_hum = 0.0
    new_hum = 0.0
    
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
            
            if (old_hum >= ref_hum) is not (new_hum >= ref_hum):
                 RelayControl(new_hum, ref_hum)
            else:
                 pass
            old_hum = new_hum

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
