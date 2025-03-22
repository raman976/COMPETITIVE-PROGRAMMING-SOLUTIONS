n=int(input())
for i in range(n):
    a, b, c = map(int, input().split())
    p=max(a, b, c) 
    count_max=(a == p) + (b == p) + (c == p) 
    if count_max>1: 
        print((p - a + 1), (p - b + 1), (p - c + 1))
    else: 
        print(0 if a == p else (p - a + 1),
              0 if b == p else (p - b + 1),
              0 if c == p else (p - c + 1))
