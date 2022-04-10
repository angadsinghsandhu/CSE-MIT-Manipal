# Client Code
import socket as sock

host = sock.gethostname()
port = 1234

PAIR = (host, port)

s = sock.socket()
s.connect(PAIR)

s.sendall(b"Welcome User")

data = s.recv(1024)
s.close()
print(str(data))
