import socket
import os

HEADER = 64
PORT = 5050
FORMAT = "utf-8"
DISCONNECT = "!DISCONNECT"
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(ADDR)

def send(msg):
    message = msg.encode(FORMAT)
    msg_length = len(message)
    send_length = str(msg_length).encode(FORMAT)
    send_length += b' ' * (HEADER - len(send_length))
    client.send(send_length)
    client.send(message)
    print(client.recv(2048).decode(FORMAT))
    
#m = input("Enter the message you want to send: ")
print(f"I am a young process who goes by the name {os.getppid()}.")
send("Hello! May I request my birthday?")
send("!DISCONNECT")