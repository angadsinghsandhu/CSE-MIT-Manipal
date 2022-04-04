import socket
serverIP = socket.gethostname()
serverPort = 16015
serverSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSock.bind((serverIP, serverPort))
serverSock.listen(1)
print("TCP server has started and is ready to receive")
connection, addr = serverSock.accept()
print("connected")
while True:
    data = connection.recv(1024)
    if not data:
        break
    data = data.decode()
    print(data)
    temp = [float(x) for x in data.split(' ')]
    print ("Received data:", temp)
    length = len(temp)
    maximum = max(temp)
    minimum = min(temp)
    total = sum(temp)
    mean = total/length
    msg = str(total) + " " + str(minimum) + " " + str(maximum) + " " + str(mean)
    connection.send(str.encode(msg))