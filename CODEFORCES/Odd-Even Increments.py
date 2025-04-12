t = int(input())
for i in range(t):
    n=int(input())
    a=list(map(int, input().split()))
    odd_indices_parity= a[0] % 2
    even_indices_parity = a[1] % 2 if n > 1 else odd_indices_parity 
    possible = True
    for i in range(0, n, 2):
        if a[i] % 2 != odd_indices_parity:
            possible = False
            break
    for i in range(1, n, 2):
        if a[i] % 2 != even_indices_parity:
            possible = False
            break
    print("YES" if possible else "NO")
