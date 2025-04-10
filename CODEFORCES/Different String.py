################################################################################
################################################################################
'''
B. Different String
time limit per test
1 second
memory limit per test
256 megabytes

You are given a string s

consisting of lowercase English letters.

Rearrange the characters of s
to form a new string r that is not equal to s

, or report that it's impossible.
Input

The first line contains a single integer t
(1≤t≤1000

) — the number of test cases.

The only line of each test case contains a string s
of length at most 10

consisting of lowercase English letters.
Output

For each test case, if no such string r

exists as described in the statement, output "NO" (without quotes).

Otherwise, output "YES" (without quotes). Then, output one line — the string r
, consisting of letters of string s

.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", and "Yes" will be recognized as a positive response).

If multiple answers are possible, you can output any of them.
Example
Input
Copy

8
codeforces
aaaaa
xxxxy
co
d
nutdealer
mwistht
hhhhhhhhhh

Output
Copy

YES
forcodesec
NO
YES
xxyxx
YES
oc
NO
YES
undertale
YES
thtsiwm
NO

Note

In the first test case, another possible answer is forcescode

.

In the second test case, all rearrangements of aaaaa
are equal to aaaaa

.
'''
################################################################################
################################################################################

from itertools import permutations
t=int(input())
for i in range(t):
    x=input()
    l=list(x)
    s=set(l)
    if len(s)==1:
        print("NO")
    else:
        found=False
        for p in permutations(l):
            k="".join(p)
            if k!=x:
                print("YES")
                print(k)
                found=True
                break
        if not found:
            print("NO")
