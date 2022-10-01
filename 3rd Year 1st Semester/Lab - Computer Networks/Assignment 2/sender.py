import socket
import time
import random
import operations as op
import stats as st

n = 0
TIMEOUT_LIMIT = 3                               # in seconds
time1 = 0
time2 = 0

sender = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sender.bind(st.ADDR)

canSend = True

# Wraps the data into the specified frame format
def makeFrame(n, data):                               # n = nth frame to send
    l = str(len(data))
    rem = op.crc4itu(data)
    
    # PADDING
    msg_n = str(n).zfill(st.N_SIZE)
    msg_l = l.zfill(st.LENGTH_SIZE)
    msg_data = data.zfill(st.DATA_SIZE)
    msg_rem = rem.zfill(st.CRC_SIZE)
    
    frame = msg_n + msg_l + msg_data + msg_rem
    return frame

# Receives ACK frame
def receiveFrame(frame):
    n = int(frame[:st.N_SIZE])                     # Extracting N
    l = int(frame[st.N_SIZE:st.N_SIZE+st.LENGTH_SIZE])   # Extracting l(length of data)
    data = str(frame[-l:])                      # Extracting data
    return n, l, data


# sends the frame to receiver
def send(conn, addr, data):
    frame = makeFrame(n, data)
    print(f"[ENCODING] Encoded frame to send: {frame}")
    frame = op.noisychannel(frame)
    print(f"[ENCODING] Frame after noisy channel: {frame}")
    #time1 = time.time();
    conn.send(frame.encode())

def recv_Ack():
    n_recv, l, data = receiveFrame()            # Extracting ACK data
    if(n_recv == n and data == 'ACK'):
        time2 = time.time()
        canSend = True
    
def timeout():
    if(time2 - time1 >= TIMEOUT_LIMIT):
        return True
    else:
        return False

def start():
    sender.listen();
    print(f"[LISTENING] Server is listening on {st.HOST_IP}")
    conn, addr = sender.accept()
    print(f"[CONNECTED] Connected to Process Id: {addr}")
    while True:
        data = input('[INPUT] Enter data to send: ')
        send(conn, addr, data)
        print("[MESSAGE SENT]")
        if data == 'q':
            print("[CLOSING] Closing the sender....")
            conn.close()
            break
        print("----------------------------------------------------")
        

start()
#print(receiveFrame(makeFrame(s, 1)))
