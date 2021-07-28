from machine import UART
from machine import Pin
import time
import _thread

txPin = Pin(4)
rxPin = Pin(5)
uart = UART(1,baudrate=115200,tx=txPin, rx=rxPin)

counter =0
while True:

    stringToWrite = 'WHY \r\n  '+ str(counter)
    print("printing ", stringToWrite)
    uart.write(str(stringToWrite))

    counter+=1

    time.sleep_ms(1000)
