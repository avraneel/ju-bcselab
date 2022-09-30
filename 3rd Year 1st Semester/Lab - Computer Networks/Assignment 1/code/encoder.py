import operations as op

def encode_vrc(frame):
    
    frame_size = len(frame)
    count = 0

    for i in range(frame_size):
        if(frame[i] == '1'):
            count += 1
    
    if(count % 2 == 0): frame += '0'
    else :              frame += '1'

    return frame

def encode_lrc(frame_list):
    
    frame_size = len(frame_list[0])
    count = 0
    parity = ''

    for i in range(frame_size):
        for j in range(len(frame_list)):
            if frame_list[j][i] == '1':
                count += 1
        if count % 2 == 0:
            parity += '0'
        else:
            parity += '1'
        count = 0

    frame_list.append(parity)

    return frame_list

def encode_crc(frame, divisor):

    remainder = op.binary_division(frame + '0000000000', divisor)
    frame += remainder

    return frame

def encode_checksum(frame_list):
    
    frame_size = len(frame_list[0])
    integers = []

    # Calculating sum in intger format
    for _, frame in enumerate(frame_list):
        integers.append(int(frame, 2))
    
    #Converting sum to binary
    bin_sum = op.warped_sum(bin(sum(integers))[2:], frame_size)

    frame_list.append(bin_sum)
    return frame_list

#print(encode_crc('110101101011', '11000110011'))