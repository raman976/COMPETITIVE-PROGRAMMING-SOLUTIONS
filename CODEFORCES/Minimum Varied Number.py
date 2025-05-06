def find_min_varied_number(s):
    digits=[]
    for i in range(9, 0, -1):
        if s >= i:
            digits.append(i)
            s -= i
    digits.sort()
    return ''.join(map(str, digits))
t = int(input())
for _ in range(t):
    s = int(input())
    print(find_min_varied_number(s))
