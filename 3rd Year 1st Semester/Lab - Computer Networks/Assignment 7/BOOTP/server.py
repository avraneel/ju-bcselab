import socket, stats as st, threading

channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

channel.bind(st.ADDR)

print(f"[LISTENING] Channel is listening on {st.HOST_IP}")
channel.listen(5)

conn, address = channel.accept()

server_ip = "140.78.129.31"

addrDict = {
    "2150::0020::3415::30cf" : "192.1.67.8",
    "1000::2000::3000::2a00" : "88.255.145.56",
    "3c56a::80bb::ac7c::5921" : "55.67.32.11",
    "8a72::b052::410c::6cce" : "11.34.128.128"
}

def send(conn):
    global addrDict, server_ip
    mac = conn.recv(1024).decode()
    print(f"[RECEIVED] Received MAC address {mac}")
    try:
        ip = addrDict[mac]
    except:
        ip = "Doesn'tt exist in table"
    print(f"[SENDING] Sending IP address...")
    conn.send(ip.encode())
    conn.send(server_ip.encode())

print('[CONNECTED] Connected to: ' + address[0] + ':' + str(address[1]))
client_thread = threading.Thread(target=send, args=(conn, ))
client_thread.start()
client_thread.join()