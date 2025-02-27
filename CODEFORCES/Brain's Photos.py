a,b=map(int,input().split())
k=[]
for i in range(a):
    l=list(map(str,input().split()))
    k.append(l)
flag=False
for i in k:
    for j in i:
        if j!="B" and j!="W" and j!="G":
            flag=True 
if flag:
    print("#Color")
else:
    print("#Black&White")