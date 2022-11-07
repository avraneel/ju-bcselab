import socket, time, threading, operations as op, stats as st

rf = 0
rn = 0
rw = 4

receiver = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
receiver.connect(st.ADDR)

def isCorrupted(data, crc):
    if op.crc4itu(data) != crc:
        return True
    else:
        return False

def Recv():
    global rn, nak_sent, bool_slot, data_slot, rw

    while True:
        
        # print("[LISTENING] Receiver is listening....")
        try:
            frame = receiver.recv(20).decode()
            recv_n, _, data, crc = op.receiveFrame(frame)
        except:
            # When everything is done, ValueError will be raised due to receiver receiving empty string
            # so we use it to terminate this thread
            return
        print(f"[RECV] Received message: {recv_n}, {data}")
      
        if isCorrupted(data, crc) == True:
            print(f"[CRC FAILURE] {op.crc4itu(data)} and {crc}")
            send_NAK(recv_n)
            print(f"[NAK SENT] Sent NAK {recv_n}") 
        else:
            print(f"[CRC SUCESS] {op.crc4itu(data)} and {crc}")
            send_Ack(recv_n)
            print(f"[ACK SENT] Sent ACK {recv_n}") 

        print("------------------------------------------------")
   
def send_Ack(seq):
    ack_frame = "11110000"
    ack_frame = op.makeFrame(seq, ack_frame)
    receiver.send(ack_frame.encode())
    
def send_NAK(recv_n):
    nak_frame = "00001111"
    nak_frame = op.makeFrame(recv_n, nak_frame)
    receiver.send(nak_frame.encode())
    
receiver_thread = threading.Thread(target=Recv)

receiver_thread.start()
receiver_thread.join()

print("[CLOSING] Closing receiver....")
receiver.close()