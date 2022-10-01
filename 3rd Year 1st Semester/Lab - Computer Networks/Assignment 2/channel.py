#There can be only one channel. So, we take it as server. Sender and receivers will be clients

import socket
import threading
import random

PORT = 8080
HOST_IP = socket.gethostbyname(socket.gethostname())
ADDR = (HOST_IP, PORT)
DISCONNECT = 'q'

channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
channel.bind(ADDR)

msg = ""

def handle_client(conn, addr):
    print(f"[NEW CONNECTION] {addr} connected.")
    
    connected = True
#while connected:
    msg = conn.recv(25).decode('utf-8')
    print(f"[{addr}] {msg}")
    #if DISCONNECT == msg:
        #break
        
    #conn.close()


def start():
    channel.listen()
    print(f"[LISTENING] Server is listening on {HOST_IP}")
    while True:
        conn, addr = channel.accept()
        print(f"[CONNECTED] Connected to Process Id: {addr}")
        thread = threading.Thread(target= handle_client, args=(conn, addr))
        thread.start()
        print(f"[ACTIVE CONNECTIONS] {threading.active_count()-1}")
        #conn.close()
    
start() 
