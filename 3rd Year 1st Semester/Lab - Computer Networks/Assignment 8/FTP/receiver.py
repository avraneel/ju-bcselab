import socket, os, threading, stats as st

ThreadCount = 0

channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

channel.connect(st.ADDR)

def send(channel):
    f = open("file2.txt", "w")
    data = channel.recv(1024).decode()
    print("[RECEIVING] Receiving file....")
    f.write(data)
    
send(channel)