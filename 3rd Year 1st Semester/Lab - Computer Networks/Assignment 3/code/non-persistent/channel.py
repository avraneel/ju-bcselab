import socket, threading, time, stats as st

ThreadCount = 0
isBusy = False

channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    channel.bind(st.ADDR)
except socket.error as e:
    print(str(e))
    
print(f"[LISTENING] Channel is listening on {st.HOST_IP}")
channel.listen(5)

def send(conn):
    global isBusy
    conn.send("[CONNECTED] Server is working.".encode())
    senders = 0
    while True:
        if isBusy == False:            
            data = conn.recv(2).decode()
            senders += 1
            isBusy = True
            print(f"[RECEIVED] Received message = {data}")
            isBusy = False
            
    conn.close()
    
def signal(conn):
    global isBusy
    while True:   
        if isBusy == True:
            conn.send(st.busy_signal.encode())
        else:
            conn.send(st.idle_signal.encode())  
    
while True:
    conn, address = channel.accept()
    print('[CONNECTED] Connected to: ' + address[0] + ':' + str(address[1]))
    client_thread = threading.Thread(target=send, args=(conn, ))
    sensing_thread = threading.Thread(target=signal, args=(conn, ))
    ThreadCount += 1
    client_thread.start()
    sensing_thread.start()
    print('[ACTIVE COUNT] Thread Number: ' + str(ThreadCount))
    
channel.close()

