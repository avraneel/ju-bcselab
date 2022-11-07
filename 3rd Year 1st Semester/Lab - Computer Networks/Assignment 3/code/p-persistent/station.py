import socket, threading, time, os, random, stats as st

station = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

canSend = False

p = 0.5
time_slot = 3

random.seed(os.getpid())

print("[WAITING] Waiting for connection response")

try:
    station.connect(st.ADDR)
except socket.error as e:
    print(str(e))
    
res = station.recv(30).decode()
print(res)

fileno = input("Enter fileno to start: ")

f = open("data"+fileno+".txt", "r")
list_of_frames = f.readlines()

def send():
    global list_of_frames
    i = 0
    while True and i < 10:
        if canSend:
            frame = list_of_frames[i].strip()
            station.send(frame.encode())
            print(f"[SENDING] Sent message: {frame}")
            time.sleep(1)
            i += 1
        else: 
            continue

def sense():
    global canSend
    flag1 = False
    flag2 = False
    while True:
        
        signal = station.recv(8).decode()
        
        if signal == st.busy_signal and flag1 == False:
            print("[BUSY] Sensing channel to be busy")           
            canSend = False
            flag1 = True
            time.sleep(time_slot)
            flag2 = False
            
        elif signal == st.idle_signal and flag2 == False:
            print("[IDLE] Sensing channel to be idle")
            
            probability = random.randint(1,10)/10
            print(f"Probability is = {probability}")
            
            if(probability <= p):
                print("[ALLOWED] Transmission allowed")
                canSend = True
                flag2 = True
                flag1 = False
                
            elif probability > p:
                print(f"[WAIT] Waiting for {time_slot}")
                canSend = False
                flag1 = True
                time.sleep(time_slot)
                flag2 = False
                
                
                
                
sense_thread = threading.Thread(target=sense)
send_thread = threading.Thread(target=send)

sense_thread.start()
send_thread.start()