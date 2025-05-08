t = int(input())
for _ in range(t):
    n = int(input())
    log = input()
    time_spent = [0] * 26 

    for ch in log:
        idx = ord(ch) - ord('A')
        time_spent[idx] += 1
    solved = 0
    for i in range(26):
        if time_spent[i] >= i + 1:  
            solved += 1
    print(solved)
