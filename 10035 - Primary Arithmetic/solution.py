a = int(input())
b = int(input())

count,new = 0,0
while(a and b):
    rema,remb = a % 10,b % 10
    if(rema+remb+new>=10):
        count,new = count + 1,1
    else:
        new = 0
    a,b = a // 10,b // 10
if(new + a % 10 >= 10 or new + b % 10 >= 10):
    count += 1
print(count)