import socket
serverIP = socket.gethostname()
serverPort = 16015
clientSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSock.connect((serverIP, serverPort))
message = str(input("Input integers with space in between: "))
message2 = str(input("Enter the length of the set: "))
clientSock.send(str.encode(message))
data = clientSock.recv(1024)
data = data.decode()
temp = [float(x) for x in data.split(' ')]
print("The total of all numbers is: " + str(temp[0]))
print("The lowest number is: " + str(temp[1]))
print("The highest number is: " + str(temp[2]))
print("The mean is: " + str(temp[3]))
clientSock.close()