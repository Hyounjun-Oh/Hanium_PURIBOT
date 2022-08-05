import rclpy
import serial
import struct
import time 
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from std_msgs.msg import Int16

class PMS7003(object):

    # PMS7003 protocol data (HEADER 2byte + 30byte)
    PMS_7003_PROTOCOL_SIZE = 32

    # PMS7003 data list
    HEADER_HIGH            = 0  # 0x42
    HEADER_LOW             = 1  # 0x4d
    FRAME_LENGTH           = 2  # 2x13+2(data+check bytes) 
    DUST_PM1_0_CF1         = 3  # PM1.0 concentration unit μ g/m3（CF=1，standard particle）
    DUST_PM2_5_CF1         = 4  # PM2.5 concentration unit μ g/m3（CF=1，standard particle）
    DUST_PM10_0_CF1        = 5  # PM10 concentration unit μ g/m3（CF=1，standard particle）
    DUST_PM1_0_ATM         = 6  # PM1.0 concentration unit μ g/m3（under atmospheric environment）
    DUST_PM2_5_ATM         = 7  # PM2.5 concentration unit μ g/m3（under atmospheric environment）
    DUST_PM10_0_ATM        = 8  # PM10 concentration unit μ g/m3  (under atmospheric environment) 
    DUST_AIR_0_3           = 9  # indicates the number of particles with diameter beyond 0.3 um in 0.1 L of air. 
    DUST_AIR_0_5           = 10 # indicates the number of particles with diameter beyond 0.5 um in 0.1 L of air. 
    DUST_AIR_1_0           = 11 # indicates the number of particles with diameter beyond 1.0 um in 0.1 L of air. 
    DUST_AIR_2_5           = 12 # indicates the number of particles with diameter beyond 2.5 um in 0.1 L of air. 
    DUST_AIR_5_0           = 13 # indicates the number of particles with diameter beyond 5.0 um in 0.1 L of air. 
    DUST_AIR_10_0          = 14 # indicates the number of particles with diameter beyond 10 um in 0.1 L of air. 
    RESERVEDF              = 15 # Data13 Reserved high 8 bits
    RESERVEDB              = 16 # Data13 Reserved low 8 bits
    CHECKSUM               = 17 # Checksum code


    # header check 
    def header_chk(self, buffer):

        if (buffer[self.HEADER_HIGH] == 66 and buffer[self.HEADER_LOW] == 77):
            return True

        else:
            return False

    # chksum value calculation
    def chksum_cal(self, buffer):

        buffer = buffer[0:self.PMS_7003_PROTOCOL_SIZE]

        # data unpack (Byte -> Tuple (30 x unsigned char <B> + unsigned short <H>))
        chksum_data = struct.unpack('!30BH', buffer)

        chksum = 0

        for i in range(30):
            chksum = chksum + chksum_data[i]

        return chksum

    # checksum check
    def chksum_chk(self, buffer):   
        
        chk_result = self.chksum_cal(buffer)
        
        chksum_buffer = buffer[30:self.PMS_7003_PROTOCOL_SIZE]
        chksum = struct.unpack('!H', chksum_buffer)
        
        if (chk_result == chksum[0]):
            return True

        else:
            return False

    # protocol size(small) check
    def protocol_size_chk(self, buffer):

        if(self.PMS_7003_PROTOCOL_SIZE <= len(buffer)):
            return True

        else:
            return False

    # protocol check
    def protocol_chk(self, buffer):
        
        if(self.protocol_size_chk(buffer)):
            
            if(self.header_chk(buffer)):
                
                if(self.chksum_chk(buffer)):
                    
                    return True
                else:
                    print("Chksum err")
            else:
                print("Header err")
        else:
            print("Protol err")

        return False 

    # unpack data 
    # <Tuple (13 x unsigned short <H> + 2 x unsigned char <B> + unsigned short <H>)>
    def unpack_data(self, buffer):
        
        buffer = buffer[0:self.PMS_7003_PROTOCOL_SIZE]

        # data unpack (Byte -> Tuple (13 x unsigned short <H> + 2 x unsigned char <B> + unsigned short <H>))
        data = struct.unpack('!2B13H2BH', buffer)

        return data


    def print_serial(self, buffer):
        
        chksum = self.chksum_cal(buffer)
        data = self.unpack_data(buffer)

        print ("============================================================================")
        print ("Header : %c %c \t\t | Frame length : %s" % (data[self.HEADER_HIGH], data[self.HEADER_LOW], data[self.FRAME_LENGTH]))
        print ("PM 1.0 (CF=1) : %s\t | PM 1.0 : %s" % (data[self.DUST_PM1_0_CF1], data[self.DUST_PM1_0_ATM]))
        print ("PM 2.5 (CF=1) : %s\t | PM 2.5 : %s" % (data[self.DUST_PM2_5_CF1], data[self.DUST_PM2_5_ATM]))
        print ("PM 10.0 (CF=1) : %s\t | PM 10.0 : %s" % (data[self.DUST_PM10_0_CF1], data[self.DUST_PM10_0_ATM]))
        print ("0.3um in 0.1L of air : %s" % (data[self.DUST_AIR_0_3]))
        print ("0.5um in 0.1L of air : %s" % (data[self.DUST_AIR_0_5]))
        print ("1.0um in 0.1L of air : %s" % (data[self.DUST_AIR_1_0]))
        print ("2.5um in 0.1L of air : %s" % (data[self.DUST_AIR_2_5]))
        print ("5.0um in 0.1L of air : %s" % (data[self.DUST_AIR_5_0]))
        print ("10.0um in 0.1L of air : %s" % (data[self.DUST_AIR_10_0]))
        print ("Reserved F : %s | Reserved B : %s" % (data[self.RESERVEDF],data[self.RESERVEDB]))
        print ("CHKSUM : %s | read CHKSUM : %s | CHKSUM result : %s" % (chksum, data[self.CHECKSUM], chksum == data[self.CHECKSUM]))
        print ("============================================================================")
        
    def pm10_pm25(self, buffer):
        
        chksum = self.chksum_cal(buffer)
        data = self.unpack_data(buffer)

class PolluPub(Node, PMS7003):

    def __init__(self,ser):
        super().__init__('PolluPublisher')
        self.ser = ser
        self.ser.flushInput()
        self.buffer = ser.read(1024)
    
        QOS_RKL10V = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            durability=QoSDurabilityPolicy.VOLATILE)
            
        self.publisher_pollu_grade = self.create_publisher(
            Int16,
            'pollu_grade',
            QOS_RKL10V
            )
            
            
    def pub_pollu_grade(self):
        
        msg = Int16()
        msg.data = self.calculate_pollu()
        self.publisher_pollu_grade.publish(msg)
        self.get_logger().info('현재 오염도 수치는 : {0}, PM10 {1}, PM2.5 {2}'.format(msg.data,self.pm10,self.pm2_5))
  
    def calculate_pollu(self):
        
        chksum = self.chksum_cal(buffer)
        data = self.unpack_data(buffer)
        
        self.pm10 = data[self.DUST_PM10_0_CF1]
        self.pm2_5 = data[self.DUST_PM2_5_CF1]
        
        if self.pm10 > 70 or self.pm2_5 > 40:
            self.pollu = 3
        elif self.pm10 > 50 or self.pm2_5 > 30:
            self.pollu = 2
        elif self.pm10 > 30 or self.pm2_5 > 20:
            self.pollu = 1
        else:
            self.pollu = 0
     
        return self.pollu
        
def main(args=None):
    rclpy.init(args=args) # 초기화 
    UART = '/dev/ttyAMA4'
    SERIAL_PORT = UART
    Speed = 9600
    ser = serial.Serial(SERIAL_PORT, Speed, timeout = 1)
    pollu = PolluPub(ser)
    
    try:
        rclpy.spin(pollu) # 콜백함수 실행 
    except KeyboardInterrupt: # 'Ctrl+c'와 같은 인터럽트 시그널 예외 상황 
        pollu.get_logger().info('Keyboard Interrupt (SIGINT)')
    finally: 
        pollu.destroy_node() # 노드 소멸 
        rclpy.shutdown() # 함수 종료

if __name__ == '__main__':
    main()        
