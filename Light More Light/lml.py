from math import sqrt,ceil
def factor(n):
    counter = 0
    for i in range(1,int(sqrt(n))+1):
        if n % i == 0:
            if i * i == n:
                counter += 1
            else:
                counter += 2
    return counter

n = int(input())
result = "yes" if factor(n) % 2 != 0 else "no"
print(result)