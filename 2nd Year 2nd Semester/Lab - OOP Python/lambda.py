a = 50
lst = []
for i in range(1,51,1):
    lst.insert(i-1, i)
f = filter(lambda n : n % 5 == 0, lst)
print(list(f))