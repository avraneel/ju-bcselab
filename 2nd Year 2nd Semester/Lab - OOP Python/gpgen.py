import time
a = int(input("Enter a = "))
q = int(input("Enter q = "))
term = a
start = time.time()
while term <= 1000000:
    term = term*q
    print(term)
print("Loop time = ", time.time() - start)