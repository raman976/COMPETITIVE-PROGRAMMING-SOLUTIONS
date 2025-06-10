#####################################################
#####################################################
'''
A. System of Equations
time limit per test
2 seconds
memory limit per test
256 megabytes

Furik loves math lessons very much, so he doesn't attend them, unlike Rubik. But now Furik wants to get a good mark for math. For that Ms. Ivanova, his math teacher, gave him a new task. Furik solved the task immediately. Can you?

You are given a system of equations:

You should count, how many there are pairs of integers (a, b) (0 ≤ a, b) which satisfy the system.
Input

A single line contains two integers n, m (1 ≤ n, m ≤ 1000) — the parameters of the system. The numbers on the line are separated by a space.
Output

On a single line print the answer to the problem.
Examples
Input
Copy

9 3

Output
Copy

1

Input
Copy

14 28

Output
Copy

1

Input
Copy

4 20

Output
Copy

0

Note

In the first sample the suitable pair is integers (3, 0). In the second sample the suitable pair is integers (3, 5). In the third sample there is no suitable pair.
'''
#####################################################
#####################################################


n,m=map(int,input().split())
l1=[]
count=0
for i in range(0,1000):
    for j in range(0,1000):
        if i*i+j==n and i+j*j==m:
            count+=1
print(count)