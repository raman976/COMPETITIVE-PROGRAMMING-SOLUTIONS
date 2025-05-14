def line_up_time(x, soldiers):
    tallest_pos = soldiers.index(max(soldiers))
    shortest_pos = len(soldiers) - 1 - soldiers[::-1].index(min(soldiers))
    if tallest_pos > shortest_pos:
        return tallest_pos + (x - 1 - shortest_pos) - 1
    else:
        return tallest_pos + (x - 1 - shortest_pos)
x = int(input())
soldiers = list(map(int, input().split()))
print(line_up_time(x, soldiers))