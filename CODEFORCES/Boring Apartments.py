n=int(input())
a=[1,11,111,1111,2,22,222,2222,3,33,333,3333,4,44,444,4444,5,55,555,5555,6,66,666,6666,7,77,777,7777,8,88,888,8888,9,99,999,9999,]
b=[1,2,3,4]*9
pre=[0]
for i in range(len(b)):
    pre.append(pre[i]+b[i])
pre.pop(0)
for i in range(n):
    j=int(input())
    k=a.index(j)
    print(pre[k])
