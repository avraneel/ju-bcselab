import random

def noisychannel(frame):

    frame_list = list(frame)  #   Converting frame in string for to list
    no_of_bits_changed =  random.randint(0,len(frame)-1)
    enum = enumerate(frame_list)

    positions = random.sample(list(enum), no_of_bits_changed)

    for _, (index, _) in enumerate(positions):
        if frame_list[index] == '0':
            frame_list[index] = '1'
        elif frame_list[index] == '1':
             frame_list[index] = '0'

    return ''.join(frame_list)

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

def warped_sum(sum, frame_size):        # sum is a binary string

    while(len(sum) > frame_size):

        slice = len(sum) - frame_size
        sum = bin(int(sum[0:slice], 2) + int(sum[slice:], 2))[2:]

    max_bit = '1'*frame_size
    sum = bin(int(max_bit, 2) - int(sum,2))[2:]

    #padding zeros before if len(sum) < frame_size

    sum = '0'*(frame_size - len(sum)) + sum

    return sum

def readfile(filename, frame_size):    #Tokenize the file contents into frames

    list = []

    f = open(filename, 'r')
    input = f.read()
    f.close()

    total_length = len(input)

    for i in range(0, total_length, frame_size):
        list.append(input[i:i+frame_size])


    #PADDING-------------------------------------------------------------
    if(len(list[len(list)-1]) < frame_size):
        list[len(list)-1] += '0'*(frame_size - len(list[len(list)-1]))

    return list

def writefile(filename, frame_list):

    f = open(filename, 'w')

    for i in range(len(frame_list)):
        f.write(frame_list[i])

    f.close()