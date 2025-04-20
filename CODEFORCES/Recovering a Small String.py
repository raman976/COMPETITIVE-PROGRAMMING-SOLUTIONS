def f():
    q=int(input())
    for x in range(q):
        r=int(input())
        found=False
        for i in range(1, 27):
            for g in range(1, 27):
                k=r-i-g
                if 1<=k<=26:
                    w=chr(ord('a')+i-1)+chr(ord('a')+g-1)+chr(ord('a')+k-1)
                    print(w)
                    found=True
                    break
            if found:
                break
f()