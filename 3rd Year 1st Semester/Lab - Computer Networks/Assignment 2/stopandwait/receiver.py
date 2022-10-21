import socket
import time
import operations as op
import stats as st

rn = 0 # Sequence number

receiver = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
receiver.connect(st.ADDR)
# receiver.settimeout(3)

def isCorrupted(data, crc):
    if op.crc4itu(data) != crc:
        return True
    else:
        return False

def Recv():
    global rn

    while True:
        
        print("[LISTENING] Receiver is listening....")
        frame = receiver.recv(20).decode()
        recv_n, _, data, crc = op.receiveFrame(frame)
        print(f"[RECV] Received message: {data}")
        
        # Checking if disconnect statement is there
        if data == 'q':
            print("[CLOSING] Closing the receiver....")
            receiver.close()
            return
        
        if recv_n == rn:
                
                if isCorrupted(data, crc) == False: # No crc error
                    print(f"[CRC SUCCESS] {op.crc4itu(data)} and {crc}")
                    send_Ack()
                    rn += 1
                    print(f"[ACK SENT] Sent ACK")
                    print("[TRANSACTION COMPLETED]")
                    
                else:
                    print(f"[CRC FAILURE] {op.crc4itu(data)} and {crc}")
                    #receiver.settimeout(3)
        else:
            print("Wrong receiveer")
        print("------------------------------------------------")
   
def send_Ack():
    ack_frame = "11110000"
    ack_frame = op.makeFrame(rn, ack_frame)
    receiver.send(ack_frame.encode())
    
Recv()