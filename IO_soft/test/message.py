import serial
from time import sleep

if __name__ == "__main__":

    ser = serial.Serial('/dev/ttyACM0')  # open serial port
    ser.baudrate = 115200
    print(ser.name)         # check which port was really used
    print(" online ! ")

    message = b'2 1500\n'
    print(len(message))
    ser.write(message)     # write a string
    ser.close() 