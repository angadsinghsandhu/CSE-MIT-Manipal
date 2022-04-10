# server code 
import socket as sock

host = sock.gethostname()
port = 1234
PAIR = (host, port)

s = sock.socket()

s.bind(PAIR)
s.listen(5)

conn, addr = s.accept()
print("Got a connection from : {} ({})".format(addr[0], addr[1]))
print("Thank you for connecting...")

while True:
    data = conn.recv(1024)
    if not data : break
    conn.sendall(data)

conn.close()