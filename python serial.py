import serial

ser = serial.Serial("COM3", 9600)

running = True

while running:
	x = ser.read(2)
	print(int.from_bytes(x, byteorder='little'))