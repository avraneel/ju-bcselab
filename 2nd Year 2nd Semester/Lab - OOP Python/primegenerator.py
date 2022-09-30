import math

end = int((input('Enter the upper limit = ')))
start = 2
while start <= end:
    flag = True
    root = int(math.sqrt(start))
    for i in range(2, root + 1, 1):
        if start % i == 0:
            flag = False
            break
    if flag == True:
        print(start)
    start += 1


