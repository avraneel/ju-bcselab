import random
import stats as st
import time

# For sake of convinience we are only injecting error in the data part

def noisychannel(frame):

    frame_list = list(frame[-st.CRC_SIZE-st.DATA_SIZE:-st.CRC_SIZE])  # Converting frame in string for to list
    no_of_bits_changed =  random.randint(0,len(frame_list)-1)
    enum = enumerate(frame_list)

    positions = random.sample(list(enum), no_of_bits_changed)

    for _, (index, _) in enumerate(positions):
        if frame_list[index] == '0':
            frame_list[index] = '1'
        elif frame_list[index] == '1':
            frame_list[index] = '0'
            
    new_frame = frame[0:st.N_SIZE] + frame[st.N_SIZE:st.N_SIZE+st.LENGTH_SIZE] + ''.join(frame_list) + frame[-st.CRC_SIZE:]
    return new_frame

def delay():
    time.sleep(random.randint()% 6)

def xor(a, b):

    val = ''
    for i in range(len(b)):
        if(a[i] == b[i]):
            val += '0'
        else:
            val += '1'
    
    return val

def binary_division(dividend, divisor):

    rem = dividend[0:len(divisor)]
    i = len(divisor)

    while(len(rem) == len(divisor)):

        if(rem[0] != '0'):
            rem = xor(rem, divisor)[1:]
        else:
            rem = rem[1:]

        if(i == len(dividend)):
            break

        rem += dividend[i]
        i += 1

    return rem


def crc4itu(frame):

    divisor = "10011"
    remainder = binary_division(frame + '0000', divisor)
    
    return str(remainder)


# Wraps the data into the specified frame format
def makeFrame(n, data):                               # n = nth frame to send
    l = str(len(data))
    rem = crc4itu(data)
    
    # PADDING
    msg_n = str(n).zfill(st.N_SIZE)
    msg_l = l.zfill(st.LENGTH_SIZE)
    msg_data = data.zfill(st.DATA_SIZE)
    msg_rem = rem.zfill(st.CRC_SIZE)
    
    frame = msg_n + msg_l + msg_data + msg_rem
    return frame

def receiveFrame(frame):
    crc = int(frame[-st.CRC_SIZE:])
    
    n = int(frame[:st.N_SIZE]) # Extracting N
    
    # Extracting length
    l = int(frame[st.N_SIZE:st.N_SIZE+st.LENGTH_SIZE])  

    data = frame[-st.CRC_SIZE-l:-st.CRC_SIZE]
    if data == "q":
        crc = ""
    else:
        # Extracting CRC code
        crc = frame[-st.CRC_SIZE:]
    return n, l, data, crc