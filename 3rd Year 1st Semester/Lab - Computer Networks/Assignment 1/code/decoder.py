import operations as op

def decode_vrc(frame):

    res = []

    frame_size = len(frame) - 1
    count = 0

    for i in range(frame_size):
        if frame[i] == '1':
            count += 1
            
    if  int(frame[frame_size]) == count % 2:
        res.append('pass')
    else:
        res.append('fail')

    return res  

def decode_lrc(frame_list):

    res = []
    parity = '' 

    frame_size = len(frame_list[0])
    count = 0

    for i in range(frame_size):
        for j in range(len(frame_list) - 1):
            if frame_list[j][i] == '1':
                count += 1
        if count % 2 == 0:
            parity += '0'
        else:
            parity += '1'
        count = 0

    if parity == frame_list[len(frame_list) - 1]:
        res.append('pass')
    else:
        res.append('fail')

    print('Calculated parity: ')
    print(parity)
    return res  

def decode_crc(frame, divisor):

    res = []
    remainder = op.binary_division(frame, divisor)
    if int(remainder, 2) == 0:
        res.append('pass')
    else:
        res.append('fail')

    return res

def decode_checksum(frame_list):

    res = []

    frame_size = len(frame_list[0])
    integers = []

    for _, frame in enumerate(frame_list):
        integers.append(int(frame, 2))
    
    bin_sum = op.warped_sum(bin(sum(integers))[2:], frame_size)

    if int(bin_sum, 2) == 0:
        res.append('pass')
    else:
        res.append('fail')

    print(bin_sum)
    return res

#print(decode_crc('1101011010110010111011', '11000110011'))



