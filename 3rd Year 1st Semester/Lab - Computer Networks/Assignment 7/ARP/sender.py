import socket, stats as st, threading

channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

channel.bind(st.ADDR)

addrDict = {
    "192.1.67.8" : "00:00:5e:00:53:af",
    "88.255.145.56" : "00:1b:63:84:45:e6",
    "55.67.32.11" : "00:11:20:c5:bc:b0",
    "11.34.128.128" : "53:ff:c1:7a:8b:9c"
}

print(f"[LISTENING] Channel is listening on {st.HOST_IP}")
channel.listen(5)

conn, address = channel.accept()

def send(conn):
    global addrDict
    ip = conn.recv(1024).decode()
    print(f"[RECEIVED] Received mac address {ip}")
    try:
        mac = addrDict[ip]
    except:
        mac = "Doesn't exist in table"
    print(f"[SENDING] Sending ip address...")
    conn.send(mac.encode())

print('[CONNECTED] Connected to: ' + address[0] + ':' + str(address[1]))
client_thread = threading.Thread(target=send, args=(conn, ))
client_thread.start()
client_thread.join()
    
    