#!/usr/bin/env python3
import serial
import time

# 'COM3' 부분에 환경에 맞는 포트 입력


while True:
    ser = serial.Serial("/dev/ttyACM0", 9600, timeout=1)

    if ser.readable():
        print(ser.readline().decode())
        

        

