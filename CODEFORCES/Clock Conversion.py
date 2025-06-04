t = int(input())
for _ in range(t):
    s = input()
    hh, mm = map(int, s.split(':'))
    if hh == 0:
        print(f"12:{mm:02d} AM")
    elif hh == 12:
        print(f"12:{mm:02d} PM")
    elif hh < 12:
        print(f"{hh:02d}:{mm:02d} AM")
    else:
        print(f"{hh - 12:02d}:{mm:02d} PM")
