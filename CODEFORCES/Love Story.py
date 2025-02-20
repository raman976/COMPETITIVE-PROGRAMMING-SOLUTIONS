######################################################
######################################################
'''
A. Love Story
time limit per test
1 second
memory limit per test
256 megabytes

Timur loves codeforces. That's why he has a string s
having length 10 made containing only lowercase Latin letters. Timur wants to know how many indices string s

differs from the string "codeforces".

For example string s=
"coolforsez" differs from "codeforces" in 4

indices, shown in bold.

Help Timur by finding the number of indices where string s

differs from "codeforces".

Note that you can't reorder the characters in the string s

.
Input

The first line contains a single integer t
(1≤t≤1000

) — the number of test cases.

Each test case is one line and contains the string s
, consisting of exactly 10

lowercase Latin characters.
Output

For each test case, output a single integer — the number of indices where string s

differs.
Example
Input
Copy

5
coolforsez
cadafurcie
codeforces
paiuforces
forcescode

Output
Copy

4
5
0
4
9

'''
######################################################
######################################################
n=int(input())
l=["c","o","d","e","f","o","r","c","e","s"]
for i in range(n):
    count=0
    a=list(input())
    for i in range(len(l)):
        if l[i]!=a[i]:
            count+=1
    print(count)