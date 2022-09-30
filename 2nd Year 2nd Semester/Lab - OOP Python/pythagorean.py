import math
def sq(i, j):
    return math.sqrt(i**2 + j**2)
triplet = [[i , j , sq(i, j)] for i in range(1,10,1) for j in range(1, 10, 1) if sq(i,j) % 1 == 0]
print(triplet)