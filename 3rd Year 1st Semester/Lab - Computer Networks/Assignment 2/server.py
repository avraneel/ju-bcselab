import socket
import threading

HEADER = 64
PORT = 5050
SERVER = "192.168.29.167"
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
FORMAT = "utf-8"
DISCONNECT = "!DISCONNECT"

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(ADDR)

def handle_client(conn, addr):
    print(f"[NEW CONNECTION] {addr} connected.")
    connected = True
    while connected:
        msg_length = conn.recv(HEADER).decode(FORMAT) 
        if msg_length:
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(FORMAT)
            if msg == DISCONNECT:
                connected = False
            print(f"[{addr}] {msg}")
        if msg != DISCONNECT:
            conn.send("Sure! Your birthday is on 22nd May 2002".encode(FORMAT))
        
        
def start():
    server.listen()
    print(f"[LISTENING] Server is listening on {SERVER}")
    while True:
        conn, addr = server.accept()
        print(f"Connected to {addr}")
        handle_client(conn, addr)
        #thread = threading.Thread(target=handle_client, args=(conn,addr))
        #thread.start()
        #print(f"[ACTIVE CONNECTIONS] {threading.active_count() -1}")
        conn.close()
        break
        
        

print("[STARTING] Server is starting....")
start()




