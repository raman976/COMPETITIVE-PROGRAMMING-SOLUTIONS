t = int(input())
for _ in range(t):
    b = list(map(int, input().split()))
    b.sort()
    found = False
    for i in range(5):
        for j in range(i+1, 6):
            a1 = b[i]
            a2 = b[j]
            a3 = b[6] - a1 - a2
            if a3 in b:
                print(a1, a2, a3)
                found = True
                break
        if found:
            break
