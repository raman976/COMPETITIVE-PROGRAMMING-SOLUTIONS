t=int(input())
for _ in range(t):
    n,m,x=map(int,input().split())
    x-=1
    row=x%n
    col=x//n
    ans=row*m+col+1
    print(ans)
