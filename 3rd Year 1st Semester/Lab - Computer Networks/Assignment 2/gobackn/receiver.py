from ast import arg
import socket, time, threading, operations as op, stats as st

rn = 0

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
        
        # print("[LISTENING] Receiver is listening....")
        try:
            frame = receiver.recv(20).decode()
            recv_n, _, data, crc = op.receiveFrame(frame)
        except:
            # When everything is done, ValueError will be raised due to receiver receiving empty string
            # so we use it to terminate this thread
            return
        print(f"[RECV] Received message: {recv_n}, {data}")
        
        # Checking if disconnect statement is there
      
        if isCorrupted(data, crc) == False and recv_n == rn : # No crc error
            print(f"[CRC SUCCESS] {op.crc4itu(data)} and {crc}")
            send_Ack()
            rn += 1
            print(f"[ACK SENT] Sent ACK")    
        else:
            print(f"[CRC FAILURE] {op.crc4itu(data)} and {crc}")
         
        #print("------------------------------------------------")
   
def send_Ack():
    ack_frame = "11110000"
    ack_frame = op.makeFrame(rn, ack_frame)
    receiver.send(ack_frame.encode())
    
receiver_thread = threading.Thread(target=Recv)

receiver_thread.start()
receiver_thread.join()

print("[CLOSING] Closing receiver....")
receiver.close()