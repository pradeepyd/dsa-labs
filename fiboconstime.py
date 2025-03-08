from math import sqrt, pow
import time

def fibo3(n):
    a = (1 + sqrt(5)) / 2
    b = pow(a, n)
    c = (1 - sqrt(5)) / 2
    d = pow(c, n)
    term = (b - d) / sqrt(5)
    print(f"The {n}th Fibonacci number is: {round(term)}")

n = int(input("Enter a number: "))
t1 = time.time()
fibo3(n)
t2 = time.time()
print(f"Execution time: {t2 - t1} seconds")