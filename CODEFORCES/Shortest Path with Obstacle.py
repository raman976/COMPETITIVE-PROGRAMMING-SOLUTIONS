######################################################################################
######################################################################################
'''


    Problems
    Submit
    Status
    Standings
    Custom test

A. Shortest Path with Obstacle
time limit per test
2 seconds
memory limit per test
512 megabytes

There are three cells on an infinite 2-dimensional grid, labeled A
, B, and F. Find the length of the shortest path from A to B

if:

    in one move you can go to any of the four adjacent cells sharing a side;
    visiting the cell F

    is forbidden (it is an obstacle). 

Input

The first line contains an integer t
(1≤t≤104) — the number of test cases in the input. Then t

test cases follow. Before each test case, there is an empty line.

Each test case contains three lines. The first one contains two integers xA,yA
(1≤xA,yA≤1000) — coordinates of the start cell A. The second one contains two integers xB,yB (1≤xB,yB≤1000) — coordinates of the finish cell B. The third one contains two integers xF,yF (1≤xF,yF≤1000) — coordinates of the forbidden cell F

. All cells are distinct.

Coordinate x
corresponds to the column number and coordinate y

corresponds to the row number (see the pictures below).
Output

Output t
lines. The i-th line should contain the answer for the i-th test case: the length of the shortest path from the cell A to the cell B if the cell F

is not allowed to be visited.
Example
Input
Copy

7

1 1
3 3
2 2

2 5
2 1
2 3

1000 42
1000 1
1000 1000

1 10
3 10
2 10

3 8
7 8
3 7

2 1
4 1
1 1

1 344
1 10
1 1

Output
Copy

4
6
41
4
4
2
334
'''
######################################################################################
######################################################################################
t = int(input())
lines_read = 0
while lines_read < t:
    line = input().strip()
    if line == "":
        continue 
    xA, yA = map(int, line.split())
    xB, yB = map(int, input().strip().split())
    xF, yF = map(int, input().strip().split())
    lines_read += 1
    dist = abs(xA - xB) + abs(yA - yB)
    if yA == yB == yF and min(xA, xB) < xF < max(xA, xB):
        dist += 2
    elif xA == xB == xF and min(yA, yB) < yF < max(yA, yB):
        dist += 2
    print(dist)
