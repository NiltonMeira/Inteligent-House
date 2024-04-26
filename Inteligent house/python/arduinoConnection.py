import serial
import time


class Arduino:
    arduino: serial.Serial
    
    def __init__(self) -> None:
        arduino = serial.Serial(port='COM6',   baudrate=9600)
        arduino.timeout = 1

        time.sleep(1)

        self.arduino = arduino


    def write_read(self, value):
        value += '\0'
        self.arduino.write(value.encode())
        time.sleep(0.5)
        data = self.arduino.readline().decode().strip()
        return data