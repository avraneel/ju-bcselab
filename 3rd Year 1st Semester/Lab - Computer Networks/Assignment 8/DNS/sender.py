import socket, os, threading, stats as st

ThreadCount = 0

channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

channel.bind(st.ADDR)

print(f"[LISTENING] Channel is listening on {st.HOST_IP}")
channel.listen(5)

path = "dns/"

def recv(conn):
    global path
    packet = conn.recv(1024).decode()
    req = packet.split(".")
    req.reverse()
    for i in range(0, len(req), 1):
        path += req[i] + "/"
    path += "ip.txt"
    ip = open(path, "r").read()
    conn.send(ip.encode())
    
conn, address = channel.accept()
print('[CONNECTED] Connected to: ' + address[0] + ':' + str(address[1]))
client_thread = threading.Thread(target=recv, args=(conn, ))
client_thread.start()
client_thread.join()
channel.close()