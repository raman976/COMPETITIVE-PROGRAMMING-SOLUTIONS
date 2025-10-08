# A. Equal Occurrences
# time limit per test
# 1 second
# memory limit per test
# 256 megabytes

# We call an array balanced if and only if the numbers of occurrences of any of its elements are the same. For example, [1,1,3,3,6,6]
# and [2,2,2,2] are balanced, but [1,2,3,3] is not balanced (the numbers of occurrences of elements 1 and 3

# are different). Note that an empty array is always balanced.

# You are given a non-decreasing array a
# consisting of n integers. Find the length of its longest balanced subsequence∗

# .

# ∗
# A sequence b is a subsequence of a sequence a if b can be obtained from a

# by the deletion of several (possibly, zero or all) element from arbitrary positions.
# Input

# Each test contains multiple test cases. The first line contains the number of test cases t
# (1≤t≤500

# ). The description of the test cases follows.

# The first line of each test case contains a single integer n
# (1≤n≤100) — the length of a

# .

# The second line contains n
# integers a1,a2,…,an (1≤a1≤a2≤⋯≤an≤n) — the elements of a

# .
# Output

# For each test case, output a single integer — the length of the longest balanced subsequence of a

# .
# Example
# Input
# Copy

# 4
# 5
# 1 1 4 4 4
# 2
# 1 2
# 15
# 1 1 1 1 1 2 2 2 2 3 3 3 4 4 5
# 5
# 3 3 3 3 3

# Output
# Copy

# 4
# 2
# 9
# 5

# Note

# In the first test case, the whole array a=[1,1,4,4,4]
# is not balanced because the number of occurrences of element 1 is 2, while the number of occurrences of element 4 is 3, which are not equal. The subsequence [1,1,4,4] is balanced because the numbers of occurrences of elements 1 and 4 are both 2. Thus, the length of the longest balanced subsequence of a is 4

# .

# In the second test case, the whole array a=[1,2]
# is already balanced, so the length of the longest balanced subsequence of a is 2

# .

# In the third test case, the longest balanced subsequence of a
# is [1,1,1,2,2,2,3,3,3]

# .

# In the fourth test case, the whole array a=[3,3,3,3,3]
# is already balanced, so the length of the longest balanced subsequence of a is 5

# .




def solve():
    n = int(input())
    ls = list(map(int, input().split()))
    a = [0] * n
    for x in ls:
        a[x - 1] += 1
    a = sorted(a)
    s = sum(a)
    ans = s
    for i in range(n):
        ans = min(ans, s - (n - i) * a[i])
    print(n - ans)
    return
 
 
t = int(input())
for _ in range(t):
    solve()