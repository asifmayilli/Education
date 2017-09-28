n = 20
for a in range(1,n+1):
    a3 = a**3
    if(a3>n):
        break
    for b in range(a,n+1):
        b3 = b**3
        for c in range(a+1,n+1):
            c3=c**3
            if(c3>a3+b3):
                break
            for d in range(c,n+1):
                d3=d**3
                if(c3+d3>a3+b3):
                    break
                if(c3+d3==a3+b3):
                    print(a,b,c,d, a3+b3, c3+d3, n)