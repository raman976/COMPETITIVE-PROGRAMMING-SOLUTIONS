###########################################################################
###########################################################################
'''
A. Codeforces Checking
time limit per test
1 second
memory limit per test
256 megabytes

Given a lowercase Latin character (letter), check if it appears in the string codeforces

.
Input

The first line of the input contains an integer t
(1≤t≤26

) — the number of test cases.

The only line of each test case contains a character c

 — a single lowercase Latin character (letter).
Output

For each test case, output "YES" (without quotes) if c

satisfies the condition, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).
Example
Input
Copy

10
a
b
c
d
e
f
g
h
i
j

Output
Copy

NO
NO
YES
YES
YES
YES
NO
NO
NO
NO


'''
###########################################################################
###########################################################################




n=int(input())
for i in range(n):
    a=(input())
    if a in "codeforces":
        print("YES")
    else:
        print("NO")