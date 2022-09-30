import socket

PORT = 8080
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)

N_SIZE = 2
LENGTH_SIZE = 3
DATA_SIZE = 20

receiver = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
receiver.connect(ADDR)

def receiveFrame(frame):
    n = int(frame[:N_SIZE]) # Extracting N
    l = int(frame[N_SIZE:N_SIZE+LENGTH_SIZE])   # Extracting l(length of data)
    data = str(frame[-l:])  # Extracting data
    return n, l, data

def recv():
    frame = receiver.recv(25).decode()
    n, l, data = receiveFrame(frame)
    print(data)
    