############################################################
############################################################
'''
A. Turtle and Good Strings
time limit per test
1 second
memory limit per test
256 megabytes

Turtle thinks a string s
is a good string if there exists a sequence of strings t1,t2,…,tk (k

is an arbitrary integer) such that:

    k≥2

.
s=t1+t2+…+tk
, where + represents the concatenation operation. For example, abc=a+bc
.
For all 1≤i<j≤k
, the first character of ti isn't equal to the last character of tj

    . 

Turtle is given a string s
consisting of lowercase Latin letters. Please tell him whether the string s

is a good string!
Input

Each test contains multiple test cases. The first line contains the number of test cases t
(1≤t≤500

). The description of the test cases follows.

The first line of each test case contains a single integer n
(2≤n≤100

) — the length of the string.

The second line of each test case contains a string s
of length n

, consisting of lowercase Latin letters.
Output

For each test case, output "YES" if the string s

is a good string, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
Example
Input
Copy

4
2
aa
3
aba
4
abcb
12
abcabcabcabc

Output
Copy

No
nO
Yes
YES

Note

In the first test case, the sequence of strings a,a
satisfies the condition s=t1+t2+…+tk, but the first character of t1 is equal to the last character of t2

. It can be seen that there doesn't exist any sequence of strings which satisfies all of the conditions, so the answer is "NO".

In the third test case, the sequence of strings ab,cb

satisfies all of the conditions.

In the fourth test case, the sequence of strings abca,bcab,cabc
satisfies all of the conditions.
'''
############################################################
############################################################
t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    print("YES" if s[0] != s[-1] else "NO")
