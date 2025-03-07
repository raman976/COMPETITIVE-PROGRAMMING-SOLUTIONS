t=int(input())
for i in range(t):
    n,m,k=map(int,input().split())
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    count=0
    for i in l2:
        for j in l1:
            if i+j<=k:
                count+=1 
    print(count)
    