###################################################################
###################################################################
'''
A. Calculating Function
time limit per test
1 second
memory limit per test
256 megabytes

For a positive integer n let's define a function f:

f(n) =  - 1 + 2 - 3 + .. + ( - 1)nn

Your task is to calculate f(n) for a given integer n.
Input

The single line contains the positive integer n (1 ≤ n ≤ 1015).
Output

Print f(n) in a single line.
Examples
Input
Copy

4

Output
Copy

2

Input
Copy

5

Output
Copy

-3

Note

f(4) =  - 1 + 2 - 3 + 4 = 2

f(5) =  - 1 + 2 - 3 + 4 - 5 =  - 3
'''
###################################################################
###################################################################
n=int(input())
if n % 2 == 0:
    print((n // 2))
else:
    print(-1*((n // 2) + 1))