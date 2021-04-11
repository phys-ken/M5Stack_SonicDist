import serial
ser = serial.Serial('COM6', 115200, timeout=0.1) 


String_data = ser.read()
int_data = int.from_bytes(String_data , 'big')
print(int_data)

ser.close()