import socket as sock

PAIR = (sock.gethostname(), 12345)
host, port = PAIR[0], PAIR[1]

s = sock.socket(sock.AF_INET, sock.SOCK_DGRAM)
s.bind(PAIR)

while True:
    print("Waitint for client")
    data, addr = s.recvfrom(1024)
    print("Received data : ", data.decode())

