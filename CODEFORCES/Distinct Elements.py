# B. Distinct Elements
# time limit per test
# 1.5 seconds
# memory limit per test
# 256 megabytes

# Given an array c
# , let f(c) be the number of distinct elements in c. For example, f([1,2,2])=2 because there are two distinct elements in [1,2,2]: 1 and 2. Also, define c[i,j] as the subarray∗ of c bounded by positions i and j (that is, the array [ci,ci+1,…,cj]

# ).

# There is an array a
# of size n. An array b of n elements is constructed such that bi=f(a[1,i])+f(a[2,i])+…+f(a[i,i]). You are given the array b. Find any possible a with elements 1≤ai≤n. It is guaranteed that at least one possible a

# exists.

# ∗
# An array x is a subarray of an array y if x can be obtained from y

# by the deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.
# Input

# Each test contains multiple test cases. The first line contains the number of test cases t
# (1≤t≤104

# ). The description of the test cases follows.

# The first line of each test case contains an integer n
# (1≤n≤105) – the number of elements in a and b

# .

# The second line of each test case contains n
# integers b1,b2,…,bn (1≤bi≤1018

# ).

# It is guaranteed that the sum of n
# over all test cases does not exceed 105

# .
# Output

# For each test case, print any possible a
# on a new line. The array a should satisfy 1≤ai≤n

# .

# For every test case, it is guaranteed at least one a

# that satisfies the conditions exists.
# Example
# Input
# Copy

# 4
# 3
# 1 3 6
# 3
# 1 3 5
# 3
# 1 3 4
# 4
# 1 2 3 7

# Output
# Copy

# 1 3 2
# 2 3 2
# 3 2 2
# 4 4 4 1

# Note

# Let's verify our output for the second test case is correct:

#     b1=f([2])=1

# b2=f([2,3])+f([3])=2+1=3
# b3=f([2,3,2])+f([3,2])+f([2])=2+2+1=5

import sys
#input=lambda:sys.stdin.readline().rstrip()
 
for _ in range(int(input())):
  n=int(input())
  a=[0]+[*map(int,input().split())]
  res=[]
  for i in range(n):
    diff=a[i+1]-a[i]
    if i-diff>=0:
      res.append(res[i-diff])
    else:
      res.append(i+1)
  print(*res)