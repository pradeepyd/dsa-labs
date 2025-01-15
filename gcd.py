def gcd (a,b):
    if (b==0):
        return a
    else:
        return gcd (b,a%b)
a=int (input("Enter 1st num: "))
b=int (input("Enter 2nd num: "))
print(f"The gdc of {a} and {b} is {gcd(a,b)}.")