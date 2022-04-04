import socket

ClientSocket = socket.socket()
host = '127.0.0.1'
port = 11596

print('Waiting for connection')
try:
    ClientSocket.connect((host, port))
except socket.error as e:
    print(str(e))

Response = ClientSocket.recv(1024)

while True:
    Input = input('Client Say Something: ')
    ClientSocket.send(str.encode(Input))
    Response = ClientSocket.recv(1024)
    print('From Server : ' + Response.decode())

ClientSocket.close()
