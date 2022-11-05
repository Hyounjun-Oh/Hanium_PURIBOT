#!/usr/bin/env python3
import serial

if __name__ == '__main__':
    ser = serial.Serial("/dev/ttyACM0", 9600, timeout=1)
    data = []
    data_split = []
    while True:
        res = ser.readline()
        line = res.decode('utf-8')
        data_split = line.split(' ',2)
        if len(data_split) ==1:
            pass
        else:
            data = [int(float(data_split[0])), int(float(data_split[1]))]

        print(data)
        data = []
        data_split = []
