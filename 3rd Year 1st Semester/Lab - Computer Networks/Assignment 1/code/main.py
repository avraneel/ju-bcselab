import operations as op
import encoder as e
import decoder as d

# Since the frames in VRC and CRC are independant of other frames, 
# we take the entire text as a frame in both cases 

def vrc():

    res = []
    #packet_size = 4

    with open('files/sender.txt', 'r') as f:
        data_frame = f.read()

    f.close()

    # Creating data frames
    #data_frames = op.readfile('files/sender.txt', packet_size)

    # Encoding frames into codewords

    codeword = e.encode_vrc(data_frame)

    # Writing encoded files into sender file
    #op.writefile('files/sender.txt', codewords)

    received_codeword = []

    # Passing codeword through a noisy channel
    received_codeword.append(op.noisychannel(codeword))

    # Writing the received codewords into a file
    op.writefile('files/receiver.txt', received_codeword)

    #received_dataword = op.readfile('files/receiver.txt', packet_size+1)

    with open('files/receiver.txt', 'r') as f:
        received_dataword = f.read()

    f.close()

    # Checking for errors
    res = d.decode_vrc(received_dataword)

    print(codeword)
    print(received_dataword)
    print(res)
    print('--------------------------------------------------------')
    return res

def lrc():

    res = []
    packet_size = 4

    # Creating data frames
    data_frames = op.readfile('files/sender.txt', packet_size)

    # Encoding frames into codewords
    codewords = e.encode_lrc(data_frames)

    # Writing encoded files into sender file
    #op.writefile('files/sender.txt', codewords)

    received_codewords = []

    # Passing codewords frame by frame through a noisy channel
    for i in range(len(codewords)): 
        received_codewords.append(op.noisychannel(codewords[i]))

    # Writing the received codewords into a file
    op.writefile('files/receiver.txt', received_codewords)

    received_datawords = op.readfile('files/receiver.txt', packet_size)

    # Checking for errors
    res = d.decode_lrc(received_datawords)

    print(codewords)
    print(received_datawords)
    print(res)
    print('--------------------------------------------------------')
    return res

def crc():

    res = []
    divisor = '11000110011' #

    with open('files/sender.txt', 'r') as f:
        data_frame = f.read()

    f.close()

    # Creating data frames
    #data_frames = op.readfile('files/sender.txt', packet_size)

    # Encoding frames into codewords
    codeword = e.encode_crc(data_frame, divisor)

    # Writing encoded files into sender file
    #op.writefile('files/sender.txt', codewords)

    received_codeword = []

    # Passing codeword through a noisy channel
    received_codeword.append(op.noisychannel(codeword))

    # Writing the received codewords into a file
    op.writefile('files/receiver.txt', received_codeword)

    #received_datawords = op.readfile('files/receiver.txt', packet_size+3)

    with open('files/receiver.txt', 'r') as f:
        received_dataword = f.read()

    f.close()

    # Checking for errors
    res = d.decode_crc(received_dataword, divisor)

    print(codeword)
    print(received_dataword)
    print(res)
    print('--------------------------------------------------------')
    return res

def checksum():

    res = []
    packet_size = 4

    # Creating data frames
    data_frames = op.readfile('files/sender.txt', packet_size)

    # Encoding frames into codewords
    codewords = e.encode_checksum(data_frames)

    # Writing encoded files into sender file
    #op.writefile('files/sender.txt', codewords)

    received_codewords = []

    # Passing codewords frame by frame through a noisy channel
    for i in range(len(codewords)): 
        received_codewords.append(op.noisychannel(codewords[i]))

    # Writing the received codewords into a file
    op.writefile('files/receiver.txt', received_codewords)

    received_datawords = op.readfile('files/receiver.txt', packet_size)

    # Checking for errors
    res = d.decode_checksum(received_datawords)

    print(codewords)
    print(received_datawords)
    print(res)
    print('--------------------------------------------------------')
    return res

def execute():

    task1 = []

    task1.append(vrc())
    task1.append(lrc())
    task1.append(crc())
    task1.append(checksum())

    result = []


    print('Testng case: "Error detected  by all four schemes." ')
    if task1 == [['fail'], ['fail'], ['fail'], ['fail']]:
        print('Result: PASS')
        result.append('1')
    else:
        print('Result: FAIL')

    print('Testing case: "Error detected by checksum but not by CRC." ')
    if task1[2] == ['fail'] and task1[3] == ['pass']:
        print('Result: PASS')
        result.append('2')
    else:
        print('Result: FAIL')

    print('Testing case: "Error detected by VRC but not by CRC." ')
    if task1[0] == ['pass'] and task1[2] == ['fail']:
        print('Result: PASS')
        result.append('3')
    else:
        print('Result: FAIL')

    return result

# For performance evaluation

count1 = 0
count2 = 0
count3 = 0

#for i in range(1000):
 #   result = execute()
#
 #   if '1' in result:
  #      count1 += 1
#
 #   if '2' in result:
  #      count2 += 1
#
 #   if '3' in result:
  #      count3 += 1
#
#print(count1)
# print(count2)
#print(count3)

# Executing program

execute()