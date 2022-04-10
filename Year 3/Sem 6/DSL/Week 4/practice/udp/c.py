import socket as sock

PAIR = (sock.gethostname(), 12345)
host, port = PAIR[0], PAIR[1]

s = sock.socket(sock.AF_INET, sock.SOCK_DGRAM)

msg = "UDP Program"

print("UDP target IP : {} and Port : {}".format(host, port))

s.sendto(msg.encode(), PAIR)

