import socket
HOST = '127.0.0.1' # Standard loopback interface address (localhost)
PORT = 31622 # Port to listen on (non-privileged ports are > 1023)
s = socket.socket()
s.bind((HOST, PORT))
s.listen()

print("\nWaiting for incoming connections...\n")
conn, addr = s.accept()

print("Received connection from ", addr[0], "(", addr[1], ")\n")
s_name = conn.recv(1024)
s_name = s_name.decode()
print(s_name, "has connected to the chat room\n")
print("Enter [e] to exit chat room\n")
name = input(str("Enter your name: "))
conn.send(name.encode())

while True:
    message = input(str("Me : "))
    if message == "[e]":
        message = "Left chat room!"
        conn.send(message.encode())
        print("\n")
        break
    conn.send(message.encode())
    message = conn.recv(1024)
    message = message.decode()
    print(s_name, ":", message)
