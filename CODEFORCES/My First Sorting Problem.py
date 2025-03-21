###################################################################
###################################################################
'''
A. My First Sorting Problem
time limit per test
1 second
memory limit per test
256 megabytes

You are given two integers x
and y

.

Output two integers: the minimum of x
and y, followed by the maximum of x and y

.
Input

The first line contains a single integer t
(1≤t≤100

) — the number of test cases.

The only line of each test case contains two space-separated integers x
and y (0≤x,y≤9

).
Output

For each test case, output two integers: the minimum of x
and y, followed by the maximum of x and y

.
Example
Input
Copy

10
1 9
8 4
1 4
3 4
2 0
2 4
6 9
3 3
0 0
9 9

Output
Copy

1 9
4 8
1 4
3 4
0 2
2 4
6 9
3 3
0 0
9 9

'''
###################################################################
###################################################################

t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    if a>b:
        print(b,a)
    else:
        print(a,b)