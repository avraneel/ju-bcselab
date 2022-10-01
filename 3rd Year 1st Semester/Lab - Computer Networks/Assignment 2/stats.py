import socket

# SOCKET VARIABLES
PORT = 8080
HOST_IP = socket.gethostbyname(socket.gethostname())
ADDR = (HOST_IP, PORT)

# DISCONNECT MESSAGE
DISCONNECT = 'q'

# SIZE OF FRAME PARTS
N_SIZE = 2
LENGTH_SIZE = 3
DATA_SIZE = 10
CRC_SIZE = 4

# FRAME FORMAT = [NN][LLL][DDDDDDDDDDDDDDD][CCCCCC]        
# where D --> data, L --> length, N --> pckt no., C --> CRC