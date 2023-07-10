import RPi.GPIO as GPIO  
from time import sleep   
GPIO.setmode(GPIO.BCM)    
GPIO.setup(21, GPIO.IN)    # thiết lập chân kết nối số 21 cho cảm biến khí gas

try:                     
    while True:          
        value = GPIO.input(21)
        if value == 1: # Kiem tra nhan tin hieu o GPIO4 hay khong
            print("phat hien co khi gas")
        else:  
            print("khong phat hien co khi gas") 
        sleep(1)        # đợi 1s
finally:                  
    print("Cleaning up...")
    GPIO.cleanup()       
    