
table = [-1] * 1005

def fibo(n):
    if n == 1 or n == 2:
        return 1
    else:
        if table[n] == -1:
            table[n] = fibo(n - 1) + fibo(n - 2)
        return table[n]

for i in range(1, 100):
    table[i] = -1

n = int(input("Enter n: "))
print(f"Ans is {fibo(n)}.")
