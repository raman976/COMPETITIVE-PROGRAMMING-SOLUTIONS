t=int(input())
for i in range(t):
    a=int(input())
    s1=input()
    s2=input()
    flag=True
    s1=list(s1)
    s2=list(s2)
    for i in range(a):
        # if s1[i]!=s2[i] and (not(s1[i]!="B" and s1[i]!="G") or not(s1[i]!="G" and s2[i]!="B")):
        #     flag=False
         if s1[i]!=s2[i] and not (s1[i] in 'BG' and s2[i] in 'BG'):
            flag = False
            break 
    if flag:
        print("YES")
    else:
        print("NO")