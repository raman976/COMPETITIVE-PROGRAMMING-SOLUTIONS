##########################################################################################
##########################################################################################
'''
A. A+B Again?
time limit per test
1 second
memory limit per test
256 megabytes

Given a two-digit positive integer n

, find the sum of its digits.
Input

The first line contains an integer t
(1≤t≤90

) — the number of test cases.

The only line of each test case contains a single two-digit positive integer n
(10≤n≤99

).
Output

For each test case, output a single integer — the sum of the digits of n

.
Example
Input
Copy

8
77
21
40
34
19
84
10
99

Output
Copy

14
3
4
7
10
12
1
18


'''
##########################################################################################
##########################################################################################
n=int(input())
for i in range(n):
   p=(input())
   l=list(p)
   print(int(l[0])+int(l[1]))