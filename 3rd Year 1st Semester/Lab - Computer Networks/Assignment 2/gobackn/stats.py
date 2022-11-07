import socket
import time
import random

# SOCKET VARIABLES
PORT = 8081
HOST_IP = socket.gethostbyname(socket.gethostname())
ADDR = (HOST_IP, PORT)

# DISCONNECT MESSAGE
DISCONNECT = '1111'

# SIZE OF FRAME PARTS
N_SIZE = 2
LENGTH_SIZE = 3
DATA_SIZE = 11
CRC_SIZE = 4

ack_frame = "11110000"

# FRAME FORMAT = [NN][LLL][DDDDDDDDDDDDDDD][CCCCCC]        
# where D --> data, L --> length, N --> pckt no., C --> CRC