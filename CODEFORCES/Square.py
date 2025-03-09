#################################################################
#################################################################
'''
A. Square
time limit per test
1 second
memory limit per test
256 megabytes

A square of positive (strictly greater than 0

) area is located on the coordinate plane, with sides parallel to the coordinate axes. You are given the coordinates of its corners, in random order. Your task is to find the area of the square.
Input

Each test consists of several testcases. The first line contains one integer t
(1≤t≤100

) — the number of testcases. The following is a description of the testcases.

Each testcase contains four lines, each line contains two integers xi,yi
(−1000≤xi,yi≤1000

), coordinates of the corners of the square.

It is guaranteed that there is a square with sides parallel to the coordinate axes, with positive (strictly greater than 0

) area, with corners in given points.
Output

For each test case, print a single integer, the area of the square.
Example
Input
Copy

3
1 2
4 5
1 5
4 2
-1 1
1 -1
1 1
-1 -1
45 11
45 39
17 11
17 39

Output
Copy

9
4
784
'''
#################################################################
#################################################################
n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    c,d=map(int,input().split())
    e,f=map(int,input().split())
    g,h=map(int,input().split())
    if a!=c:
        l=abs(c-a)
    elif a!=e:
        l=abs(e-a)
    elif a!=g:
        l=abs(g-a)
    if b!=d:
        h=abs(d-b)
    elif b!=f:
        h=abs(f-b)
    elif b!=h:
        h=abs(h-b)
    print(l*h)