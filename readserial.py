import serial
ser = serial.Serial('/dev/ttyACM3', 9600)  # open serial port
print(ser.name)         # check which port was really used

while(1):
    line = ser.readline()
    print line
