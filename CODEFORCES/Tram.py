n=int(input())
master=[]
for i in range(n):
    l=list(map(int,input().split()))
    master.append(l)
start=0
m=0
for i in master:
    m=max(m,start-i[0]+i[1])
    start=start-i[0]+i[1]
print(m)
   
    