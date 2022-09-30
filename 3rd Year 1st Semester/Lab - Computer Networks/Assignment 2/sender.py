import socket
import time

# FRAME FORMAT = [NN][LLL][DDDDDDDDDDDDDDDDDDDD]        
# where D --> data, L --> length, N --> pckt no.

# SOCKET VARIABLES
PORT = 8080
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)

# SIZE OF FRAME PARTS
N_SIZE = 2
LENGTH_SIZE = 3
DATA_SIZE = 20

n = 0
TIMEOUT_LIMIT = 3   # in seconds
time1 = 0
time2 = 0

sender = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sender.connect(ADDR)

canSend = True

# TODO add a error injection inside sender file only

# Wraps the data into the specified frame format
def makeFrame(n):     # n = nth frame to send
    data = input('Enter data to send: ')
    l = str(len(data))
    
    # PADDING
    msg_n = str(n).zfill(N_SIZE)
    msg_l = l.zfill(LENGTH_SIZE)
    msg_data = data.zfill(DATA_SIZE)
    
    frame = msg_n + msg_l + msg_data
    return frame

def receiveFrame(frame):
    n = int(frame[:N_SIZE]) # Extracting N
    l = int(frame[N_SIZE:N_SIZE+LENGTH_SIZE])  # Extracting l(length of data)
    data = str(frame[-l:])  # Extracting data
    return n, l, data

def send():
    frame = makeFrame(n)
    time1 = time.time();
    sender.send(frame.encode())

def recv_Ack():
    n_recv, l, data = receiveFrame()    # Extracting ACK data
    if(n_recv == n and data == 'ACK'):
        time2 = time.time()
        canSend = True
    
def timeout():
    if(time2 - time1 >= TIMEOUT_LIMIT):
        return True
    else:
        return False

send()

#print(receiveFrame(makeFrame(s, 1)))
