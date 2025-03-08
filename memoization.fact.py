import time

table = {}

def fact(n):
    if n == 0 or n == 1:
        return 1
    else:
        if n not in table:
            table[n] = n*fact(n-1)
        return table[n]
    
n = int(input("Enter the value: "))
t1 = time.time()
ans = fact(n)
t2 = time.time()
print(f"The {n}th term is {ans}")
print(f"The time taken was {t2-t1} seconds")