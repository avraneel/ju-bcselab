import socket, os, threading, stats as st

ThreadCount = 0

channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

channel.bind(st.ADDR)

print(f"[LISTENING] Channel is listening on {st.HOST_IP}")
channel.listen(5)

def send(conn):
    f = open("file1.txt", "r")
    data = f.read()
    print("[SENDING] Sending file....")
    conn.send(data.encode())

conn, address = channel.accept()
print('[CONNECTED] Connected to: ' + address[0] + ':' + str(address[1]))
client_thread = threading.Thread(target=send, args=(conn, ))
client_thread.start()
client_thread.join()
