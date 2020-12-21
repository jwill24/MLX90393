import math
import serial
import sys

PI = 3.14159265358979323846
channels = 3
angle1 = PI/4.0 # 45 degrees
angle3 = PI/2.0 # 90 degrees

print()
print( 'Initializing angle 1 to %f radians and angle 3 to %f radians' % (angle1, angle3) )
print()

ser = serial.Serial('/dev/tty.usbserial-1410',115200)
ser.close()
ser.open()


def get_field(data):
    x, y, z = [], [], []

    for line in data:
        dataArray = line.readline().decode()
        dataXYZ = dataArray.split(',')
        x.append( float(dataXYZ[2]) ), y.append( float(dataXYZ[3]) ), z.append( float(dataXYZ[4]) )

    return x, y, z


def cancel_field(x,y,z):
    x1 = x[0] - ( math.cos(angle1)*x[1] + math.sin(angle1)*z[1] )
    y1 = y[0] - y[1]
    z1 = z[0] - ( math.cos(angle1)*z[1] + math.sin(angle1)*x[1] )
    
    x3 = x[2] - ( math.cos(angle3)*x[1] + math.sin(angle3)*z[1] )
    y3 = y[2] - y[1]
    z3 = z[2] - ( math.cos(angle3)*z[1] + math.sin(angle3)*x[1] )

    return x1, y1, z1, x3, y3, z3


while True:
    data = []
    for i in range(channels): data.append(ser)
    x, y, z = get_field(data)
    x1, y1, z1, x3, y3, z3 = cancel_field(x, y, z)

    print( 'Field 1 -->', 'X1:', x1, 'Y1:', y1, 'Z1:', z1 )
    print( 'Field 3 -->', 'X3:', x3, 'Y3:', y3, 'Z3:', z3 )
    print()

