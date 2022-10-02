import socket
import time
import random
import operations as op
import stats as st
import signal

rn = 0

receiver = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
receiver.connect(st.ADDR)

def isCorrupted(data, crc):
    if op.crc4itu(data) != crc:
        return True
    else:
        return False

def Recv():
    global rn
    while True:
        # receiver.setblocking(0)
        frame = receiver.recv(20).decode()
        recv_n, _, data, crc = op.receiveFrame(frame)
        
        # Checking if disconnect statement is there
        if data == 'q':
            print("[CLOSING] Closing the receiver....")
            break
        if recv_n == rn:
                print(f"[SUCCESS] Received message: {data}")
                if isCorrupted(data, crc) == False:
                    print(f"[FAILURE] CRC codes do not match: {op.crc4itu(data)} and {crc}")
                send_Ack()
                rn += 1
                print(f"[ACK SENT] Sent ACK")
                
        print("------------------------------------------------")
   
def send_Ack():
    ack_frame = "11110000"
    ack_frame = op.makeFrame(rn, ack_frame)
    print(ack_frame)
    print(rn)
    receiver.send(ack_frame.encode())
    
def send_Nak():
    nak_frame = "00001111"
    nak_frame = op.makeFrame(rn, nak_frame)
    print(nak_frame)
    print(rn)
    receiver.send(nak_frame.encode())
    
Recv()