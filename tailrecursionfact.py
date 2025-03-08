def fact(n , acc):
    if n == 1:
        return acc
    else:
        return fact(n-1 ,acc*n)
    
n = int(input("Enter the value: "))
ans = fact(n , 1)
print(f"The {n}th term is {ans}")