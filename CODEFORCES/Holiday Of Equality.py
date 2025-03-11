n=int(input())
k=list(map(int,input().split()))
if n==1:
    print(0)
else:
    cou=0
    a=max(k)
    for i in k:
        cou+=(a-i)
    print(cou)