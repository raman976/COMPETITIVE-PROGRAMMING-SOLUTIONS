import heapq



n,q=map(int,input().split())
n+=1
A=[]
for i in range(q):
    a,b=map(int,input().split())
    A.append([a,b])

order=[]
ind=[0]*n
for i in A:
    ind[i[-1]]+=1
adj=[[] for i in range(n)]
for i in A:
    adj[i[0]].append(i[-1])
queue=[]
for i in range(n):
    if ind[i]==0:
        heapq.heappush(queue,i)


while queue:
    a=heapq.heappop(queue)
    order.append(a)
    for i in adj[a]:
        ind[i]-=1
        if ind[i]==0:
            heapq.heappush(queue,i)
if len(order)>=1:
    order.pop(0)
if len(order)==n-1:
    for i in range(n-1):
        print(order[i],end=" ")
else:
    print("IMPOSSIBLE")