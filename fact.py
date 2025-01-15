def fact(n):
    if n == 1:
        return 1
    else:
        return n * fact(n - 1)

n = int(input("Enter the number: "))
factorial = fact(n)
print(f"The factorial of {n} is {factorial}")
