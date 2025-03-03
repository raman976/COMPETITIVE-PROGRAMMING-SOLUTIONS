n=int(input())
for i in range(n):
    s=input()
    if s[0]=="a" and ((s[1]=="b" and s[2]=="c") or (s[2]=="b" and s[1]=="c")):
        print("YES")
    elif s[1]=="a" and ((s[0]=="b")):
        print("YES")
    elif s[2]=="a" and (s[0]=="c"):
        print("YES")
    else:
        print("NO")
