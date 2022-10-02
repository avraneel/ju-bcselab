import socket
import time
import random
import threading
import operations as op
import stats as st

sn = 0

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

# sends the frame to receiver

def timeout():
    global time1, time2
    # print(time2-time1)
    if(time2 - time1 >= TIMEOUT_LIMIT):
        return True
    else:
        return False

def send(conn, data):
    global canSend
    global sn
    if canSend == True:
        frame = op.makeFrame(sn, data)
        print(f"[ENCODING] Encoded frame to send: {frame}")
        #frame = op.noisychannel(frame)
        print(f"[ENCODING] Frame after noisy channel: {frame}")
        global time1
        time1 = time.time();
        conn.send(frame.encode())
        copy_data = data
        copy_sn = sn
        sn += 1
        canSend = False
    
    res1, res2 = recv_Ack(conn)    
    if res1 == True and res2 == copy_sn:
        copy_sn = 0
    
    global time2    
    time2 = time.time()
    
    print("I am here")
    if timeout() == True:
        frame = op.makeFrame(copy_sn, copy_data)
        print(f"[ENCODING] Encoded frame to send: {frame}")
        #frame = op.noisychannel(frame)
        print(f"[ENCODING] Frame after noisy channel: {frame}")
        time1 = time.time();
        conn.send(frame.encode())

def recv_Ack(conn):
    global sn
    global canSend
    ack_frame = conn.recv(20).decode()
    print(ack_frame)
    n_recv, _, data,_ = op.receiveFrame(ack_frame)  
    print(n_recv)                       # Extracting ACK data
    if n_recv == copy_sn and data == '11110000':
        print(f"[ACK RECV] ACK {n_recv} successfully received.")
        canSend = True
        return True, n_recv
    else:
        print(f"Wrong ACK frame.")
        return False, n_recv

def start():
    sender.listen();
    print(f"[LISTENING] Server is listening on {st.HOST_IP}")
    conn, addr = sender.accept()
    print(f"[CONNECTED] Connected to Process Id: {addr}")
    while True:
        data = input('[INPUT] Enter data to send: ')
        send(conn, data)
        print("[Message passing SENT]")
        if data == 'q':
            print("[CLOSING] Closing the sender....")
            conn.close()
            break            
        print("----------------------------------------------------")
        

start()
