n = int(input())
t = input()
i = 0
k = 1
res = ""
while i < n:
    res += t[i]
    i += k
    k += 1
print(res)
