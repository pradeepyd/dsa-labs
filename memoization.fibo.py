import time

table = {}

def fibo(n):
    if n == 1 or n == 2:
        return 1
    else:
        if n not in table:
            table[n] = fibo(n-1)+fibo(n-2)
        return table[n]
    
n = int(input("Enter the value: "))
t1 = time.time()
ans = fibo(n)
t2 = time.time()
print(f"The {n}th term is {ans}")
print(f"The time taken was {t2-t1} seconds") 