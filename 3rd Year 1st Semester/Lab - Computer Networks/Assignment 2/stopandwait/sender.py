# Assumptions:
# 1. Resending will resend without errors
# 2. Error only occurs in data part

import socket
import time
import random
import threading
import operations as op
import stats as st

sn = 0  # Sequence number

# To calculate timeout
TIMEOUT_LIMIT = 2                           
time1 = 0
time2 = 0

sender = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sender.bind(st.ADDR)

canSend = True

# Copy to store incase we need to resend
copy_sn = 0
copy_data = ""

def send(conn, data):
    
    global canSend, time1, sn, copy_sn, copy_data
    
    # Sending frames
    if canSend == True:
        
        # Making the frame
        frame = op.makeFrame(sn, data)
        print(f"[ENCODING] Encoded frame: {frame}")
        #time.sleep(random.randint()% 6)
        frame = op.noisychannel(frame)
        print(f"[NOISY] Frame after noise: {frame}")
        
        # Sending frame
        conn.send(frame.encode())
        
        # Storing Frame
        copy_data = data
        copy_sn = sn
        
        # Starting timer
        time1 = time.time()
        
        sn += 1
        
        canSend = False
    
    if data == "q":
        return
    
    # Receing ACK
    recv_Ack(conn)  
    
    # Resending Frame
    while canSend == False:
        frame = op.makeFrame(copy_sn, copy_data)
        frame = op.noisychannel(frame)
        print(f"[RESENDING] Resending frame: {frame}")
        time1 = time.time();
        conn.send(frame.encode())
    
        # Receving Ack for the resent frame    
        recv_Ack(conn)

def recv_Ack(conn):
    
    global sn, canSend, copy_data, copy_sn, time2
    print("[Reciving ACK]......")

    # Receiving ACK Frame
    try:
        conn.settimeout(0.5)    # Setting timeout time
        ack_frame = conn.recv(20).decode()
    except:
        # Timeout has occured, so we should resend the frame
        print("---[TIMEOUT OCCURED]----")
        return
    
    ackNo, _, data,_ = op.receiveFrame(ack_frame)  
    
    # Checking if ACK Valid
    if ackNo == copy_sn and data == '11110000':
        
        # Stopping timer
        time2 = time.time()
        
        print(f"[ACK RECV] ACK {ackNo} successfully received.")
        
        # Purging data
        copy_sn = 0
        copy_data = ""
        
        canSend = True
        print("[TRANSACTION COMPLETED]")
        return
    

def start():
    
    # Listening
    sender.listen()
    print(f"[LISTENING] Server is listening on {st.HOST_IP}")
    
    # Accepting receiver
    conn, addr = sender.accept()
    print(f"[CONNECTED] Connected to Process Id: {addr}")
    
    while True:
        data = input('[INPUT] Enter data to send: ')
        
        send(conn, data)
        
        if data == 'q':
            print("[CLOSING] Closing the sender....")
            conn.close()
            break 
                   
        print("----------------------------------------------------")
        

start()
