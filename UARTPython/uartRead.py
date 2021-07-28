from machine import UART
from machine import Pin
import time
import _thread

txPin = Pin(4)
rxPin = Pin(5)
uart = UART(1,baudrate=115200,tx=txPin, rx=rxPin)


# BELOW WORKS IN READING AND DECODING
# while True:
#     rxData = bytes()
#     while uart.any() > 0:
#         rxData += uart.read(1)


#     print(rxData.decode('utf-8'))



while True:
    rxData=bytes()

    while uart.any()>0:
        rxData += uart.read(100)
    
    strDummy = rxData.decode('utf-8')
    if(len(rxData)>0):
        # print(rxData.decode('utf-8'))
        print(strDummy)