import socket
import time
import random
import operations as op
import stats as st

receiver = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
receiver.connect(st.ADDR)

def receiveFrame(frame):
    crc = int(frame[-st.CRC_SIZE:])
    
    n = int(frame[:st.N_SIZE]) # Extracting N
    
    # Extracting length
    l = int(frame[st.N_SIZE:st.N_SIZE+st.LENGTH_SIZE])  

    data = frame[-st.CRC_SIZE-l:-st.CRC_SIZE]

    # Extracting CRC code
    crc = frame[-st.CRC_SIZE:]
    return n, l, data, crc

def recv():
    while True:
        frame = receiver.recv(25).decode()
        n, l, data, crc = receiveFrame(frame)
        
        # Checking if disconnect statement is there
        if data == 'q':
            print("[CLOSING] Closing the receiver....")
            break
        
        # Checking if crc code matches
        if op.crc4itu(data) == crc:
            print(f"[SUCCESS] Received message: {data}")
        elif op.crc4itu(data) != crc:
            print(f"[FAILURE] CRC codes do not match: {op.crc4itu(data)} and {crc}")
        print("------------------------------------------------")
    
recv()