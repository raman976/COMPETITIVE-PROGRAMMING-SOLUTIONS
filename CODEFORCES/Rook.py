def rook_moves(cases):
    cols = 'abcdefgh'
    outcomes = []
    for pos in cases:
        c, r = pos[0], pos[1]
        moves = []
        for x in cols:
            if x != c:
                moves.append(f"{x}{r}")
        for y in '12345678':
            if y != r:
                moves.append(f"{c}{y}")
        outcomes.append(sorted(moves))
    for moves in outcomes:
        print(" ".join(moves))
t = int(input())
cases = [input().strip() for _ in range(t)]
rook_moves(cases)