s=input()
k=s[1:-1]
p=k.split(", ")
if len(k)!=0:
    o=set(p)
    print(len(o))
else:
    print(0)