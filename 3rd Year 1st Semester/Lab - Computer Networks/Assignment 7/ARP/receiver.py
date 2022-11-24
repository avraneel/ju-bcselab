import socket, os, threading, stats as st

channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

channel.connect(st.ADDR)

def send(channel):
    ip = input("Enter ip address = ")
    channel.send(ip.encode())
    mac = channel.recv(1024).decode()
    print(f"[RECEIVED] Your mac address is: {mac}")
    
send(channel)
