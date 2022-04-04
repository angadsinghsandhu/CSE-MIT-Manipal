import socket
import time
serversocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 9991
serversocket.bind((host, port))
while True:
    data,addr = serversocket.recvfrom(1024)
    print("Got a connection from %s" % str(addr))
    currentTime = time.ctime(time.time()) + "\r\n"
    serversocket.sendto(currentTime.encode('ascii') , addr)