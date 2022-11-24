import socket, os, threading, stats as st

ThreadCount = 0

channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

channel.connect(st.ADDR)

mac = "3c56a::80bb::ac7c::5921"

def send(channel):
    global mac
    print("[REQUESTING] Sending MAC address: ", mac)
    channel.send(mac.encode())
    ip = channel.recv(1024).decode()
    server_ip = channel.recv(1024).decode()
    print(f"[RECEIVED] My ip address is: {ip}")
    print(f"[RECEIVED] Server ip address is: {server_ip}")
    
send(channel)