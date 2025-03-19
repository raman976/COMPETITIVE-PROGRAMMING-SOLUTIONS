n=int(input())
for i in range(n):
    t=int(input())
    l=list(map(int,input().split()))
    dictn={}
    flag=False
    for i in l:
        if i not in dictn:
            dictn[i]=1
        else:
            dictn[i]+=1
        if dictn[i]>=3:
            print(i)
            flag=True 
            break
    if flag==False:
        print(-1)