n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    diff=b-a 
    if diff==0:
        print(0)
    elif diff>0 and diff%2==1:
        print(1)
    elif diff>0 and diff%2==0:
        print(2)
    elif diff<0 and diff%2==1:
        print(2)
    elif diff<0 and diff%2==0:
        print(1)