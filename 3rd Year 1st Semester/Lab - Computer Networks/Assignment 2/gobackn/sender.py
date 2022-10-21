import socket, threading, time, operations as op, stats as st

sf = 0
sn = 0
sw = 4

text = []
length = 0
flag2 = False   # used to terminate the recv_Ack thread

sender = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sender.bind(st.ADDR)

data_queue = [None]*sw

flag = False

def send(conn, f):
    
    global sn, sf, sw, data_queue, flag, text
        
    while True:
        if (sn - sf) < sw:

            try:
                data = text.pop(0)
            except:
                print("[FINISHED] All output read.")
                flag = True
                return
            
            frame = op.noisychannel(op.makeFrame(sn, data))
            print(f"[SENDING] Sending frame: {frame}")
            conn.send(frame.encode())
        
            data_queue[sn % sw] = data
            
            sn += 1

def recv_Ack(conn):
    
    global sn, sf, sw, data_queue, text, length

    # Receiving ACK Frame
    while True:
        global sf, sn, sw, data_queue, flag2
        try:
            conn.settimeout(0.5)
            recv_frame = conn.recv(20).decode()
            
            # Extracting frame details
            ackNo, _, data,_ = op.receiveFrame(recv_frame)
            
        except:
            resend_thread = threading.Thread(target=timeout_steps, args=(conn,))
            resend_thread.start()
            resend_thread.join()
            if flag2 == True:
                print("[FINISHED] All ACK received.")
                return
            continue
        
        if ackNo >= sf and ackNo <= sn and data == '11110000': # if valid ACK
            while(sf <= ackNo):
                print(f"[ACK RECV] ACK {ackNo} successfully received.")
                data_queue[sf % sw] = ""
                sf += 1       
        
        if ackNo == (length - 1):  # All ACK received
            flag2 = True
        
def timeout_steps(conn):
    global sf, sn, sw, data_queue
    temp = sf
    while(temp < sn):
        data = data_queue[temp % sw]
        frame = op.makeFrame(temp, data)
        print(f"[RE SENDING] Resending frame: {frame}")
        conn.send(frame.encode())
        temp += 1


def start():
    # Listening
    global text, length
    
    sender.listen()
    print(f"[LISTENING] Server is listening on {st.HOST_IP}")
    
    # Accepting receiver
    conn, addr = sender.accept()
    print(f"[CONNECTED] Connected to Process Id: {addr}")
    
    f = open("data.txt", "r")
    
    text = f.readlines()
    for i in range(len(text)):
        text[i] = text[i].strip()
    
    length = len(text)
    
    sender_thread = threading.Thread(target=send, args=(conn, f))
    receiver_thread = threading.Thread(target=recv_Ack, args=(conn,))
        
    sender_thread.start()
    receiver_thread.start()
    sender_thread.join()
    receiver_thread.join()
    
    print("[CLOSING] Closing sender...")
    conn.close()
    
    f.close()
    
    
start()
