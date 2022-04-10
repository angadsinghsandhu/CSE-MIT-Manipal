import socket

serv = ('172.16.57.222', 6060)
HOST, PORT = serv[0], serv[1]
s = socket.socket()
s.bind(serv)
s.listen()
print("\nWaiting for incoming connections...\n")

conn, addr = s.accept()
print("Received connection from ", addr[0], "(", addr[1], ")\n")
s_name = conn.recv(1024).decode()
print(s_name, "has connected to the chat room")
print("\nEnter 'bye' to exit chat room\n")
name = input(str("Enter your name: "))
conn.send(name.encode())
while True:
    msg = conn.recv(1024).decode()
    if(msg=='bye'):
        conn.close()
        break
    print(s_name, ":", msg)
    msg = input(str("Me : "))
    if msg == "bye":
        conn.send(msg.encode())
        print("\n")
        conn.close()
        break
    conn.send(msg.encode())