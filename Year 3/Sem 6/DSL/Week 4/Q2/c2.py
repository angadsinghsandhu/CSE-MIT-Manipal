import socket
# Port to listen on (non-privileged ports are > 1023)
serv = (socket.gethostname(), 31621)
HOST, PORT =  serv[0], serv[1]
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
name = input(str("\nEnter your name: "))
print("\nTrying to connect to ", HOST, "(", PORT, ")\n")
s.sendto(b"" , serv)
print("Connected...\n")
s.sendto(name.encode('ascii') , serv)
s_name = s.recv(1024).decode()
print(s_name, "has connected to the chat room\n")
print("Enter [e] to exit chat room\n")
while True:
    msg, addr = s.recvfrom(1024)
    msg = msg.decode()
    print(s_name, ":", msg)
    msg = input(str(">>> Enter msg : "))
    if msg == "[e]":
        msg = "Left chat room!"
        s.sendto(msg.encode() , serv)
        print("\n")
        break
    s.sendto(msg.encode() , serv)