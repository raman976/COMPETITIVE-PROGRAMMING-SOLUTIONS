# A. We Need the Zero
# time limit per test
# 1 second
# memory limit per test
# 256 megabytes

# There is an array a
# consisting of non-negative integers. You can choose an integer x and denote bi=ai⊕x for all 1≤i≤n, where ⊕ denotes the bitwise XOR operation. Is it possible to choose such a number x that the value of the expression b1⊕b2⊕…⊕bn equals 0

# ?

# It can be shown that if a valid number x
# exists, then there also exists x such that (0≤x<28

# ).
# Input

# Each test contains multiple test cases. The first line contains the number of test cases t
# (1≤t≤1000

# ). The description of the test cases follows.

# The first line of the test case contains one integer n
# (1≤n≤103) — the length of the array a

# .

# The second line of the test case contains n
# integers — array a (0≤ai<28

# ).

# It is guaranteed that the sum of n
# over all test cases does not exceed 103

# .
# Output

# For each set test case, print the integer x
# (0≤x<28) if it exists, or −1

# otherwise.
# Example
# Input
# Copy

# 5
# 3
# 1 2 5
# 3
# 1 2 3
# 4
# 0 1 2 3
# 4
# 1 2 2 3
# 1
# 1

# Output
# Copy

# 6
# 0
# 3
# -1
# 1

# Note

# In the first test case, after applying the operation with the number 6
# the array b becomes [7,4,3], 7⊕4⊕3=0

# .

# There are other answers in the third test case, such as the number 0

# .





for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    xor = 0
    for x in a:
        xor ^= x
    if xor == 0:
        print(0)
    else:
        if n % 2 == 1:
            print(xor)
        else:
            print(-1)