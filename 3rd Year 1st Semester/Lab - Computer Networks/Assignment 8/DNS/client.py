import socket, os, threading, stats as st

ThreadCount = 0

channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

channel.connect(st.ADDR)

def send(channel):
    print("[INPUT] Enter domain name: ")
    dn = input()
    channel.send(dn.encode())
    ip = channel.recv(1024).decode()
    print("[IP] IP address is: ", ip)
    
send(channel=channel)
channel.close()