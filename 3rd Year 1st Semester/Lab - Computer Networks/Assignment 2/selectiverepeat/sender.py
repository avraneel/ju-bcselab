import socket, threading, time, operations as op, stats as st

sf = 0
sn = 0
sw = 4          # 0 based indexing

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
            print(f"[SENDING] Sending frame: no. {sn}, {frame}")
            conn.send(frame.encode())
        
            data_queue[sn % sw] = data
            
            sn += 1

def recv_Ack(conn):
    
    global sn, sf, sw, data_queue, text, length

    # Receiving ACK Frame
    while True:
        global sf, sn, sw, data_queue, flag2
        
        recv_frame = conn.recv(20).decode()
            
        ackNo, _, data,_ = op.receiveFrame(recv_frame)
            
        if data == '00001111':
            if ackNo >= sf and ackNo <= sn: # if NAK
                print(f"[NAK RECV] NAK {ackNo} successfully received.")
                resend_thread = threading.Thread(target=timeout_steps, args=(conn, ackNo))
                resend_thread.start()
                resend_thread.join()
                
        if data == '11110000':
            if ackNo >= sf and ackNo <= sn: # if ACK
                print(f"[ACK RECV] ACK {ackNo} successfully received.")
            while(sf <= ackNo):
                data_queue[sf % sw] = ""
                sf += 1        
            if ackNo == 7:
                return
        
def timeout_steps(conn, ackNo):
    global sf, sn, sw, data_queue
    data = data_queue[ackNo % sw]
    frame = op.makeFrame(ackNo, data)
    print(f"[RE SENDING] Resending frame: {ackNo}, {frame}")
    conn.send(frame.encode())

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
