import socket
HOST = socket.gethostname()
PORT = 31621 # Port to listen on (non-privileged ports are > 1023)
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((HOST, PORT))
print("\nWaiting for incoming connections...\n")
data,addr = s.recvfrom(1024)
print("Received connection from ", addr[0], "(", addr[1], ")\n")

s_name, addr = s.recvfrom(1024)
s_name = s_name.decode()
print(s_name, "has connected to the chat room\n")
print("Enter [e] to exit chat room\n")
name = input(str("Enter your name: "))
s.sendto(name.encode('ascii') , addr)
while True:
    msg = input(str(">>> Enter Message : "))
    if msg == "[e]":
        msg = "Left chat room!"
        s.sendto(msg.encode() , addr)
        print("\n")
        break
    s.sendto(msg.encode() , addr)
    msg, addr = s.recvfrom(1024)
    msg = msg.decode()
    print(s_name, ":", msg)