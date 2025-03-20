t = int(input())  
for i in range(t):
    n=int(input())
    count=0
    for d in range(1, 10): 
        num = d
        while num <= n:
            count += 1
            num = num * 10 + d 
    print(count)