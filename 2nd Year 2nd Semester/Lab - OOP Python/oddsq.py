lst = []
n = int(input('Enter n = '))
for i in range(1,n+1,1):
    lst.insert(i-1, i)
m = map(lambda n : n**2, lst)
lst2 = list(m)
f = filter(lambda n : n % 2 != 0, lst2)
print(list(f))