import RPi.GPIO as GPIO
import time

PIR = 2
LED_Red = 4
#LED_Green = 3
#buzzer = 26

GPIO.setmode(GPIO.BCM)
GPIO.setup(PIR,GPIO.IN)
#GPIO.setup(LED_Green, GPIO.OUT)
GPIO.setup(LED_Red, GPIO.OUT)
#GPIO.setup(buzzer,GPIO.OUT)  

#GPIO.output(LED_Green, GPIO.LOW)
GPIO.setup(LED_Red, GPIO.OUT)
#GPIO.output(buzzer,GPIO.LOW)  

try:
    while True:
        i=GPIO.input(PIR)    # doc gia tri tu PIR
        if i == 0:
            print("Khong phat hien chuyen dong")
            #GPIO.output(LED_Green, GPIO.HIGH)
            GPIO.output(LED_Red, GPIO.LOW)
            time.sleep(3)
            
        elif i == 1:
            print("Phat hien chuyen dong !!!")
            GPIO.output(LED_Red, GPIO.HIGH)
            time.sleep(0.5)
            GPIO.output(LED_Red, GPIO.LOW)
            time.sleep(0.5)
            #GPIO.output(LED_Green, GPIO.LOW)
            #GPIO.output(buzzer, GPIO.HIGH)
            #time.sleep(3)
        
except KeyboardInterrupt:   #Ctrl+C se exit chuong trinh
    print("Quit")
    GPIO.cleanup()
