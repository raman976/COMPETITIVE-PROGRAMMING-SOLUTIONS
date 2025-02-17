###################################################
###################################################
'''
B. Prefix Removals
time limit per test2 seconds
memory limit per test256 megabytes
You are given a string 𝑠
 consisting of lowercase letters of the English alphabet. You must perform the following algorithm on 𝑠
:

Let 𝑥
 be the length of the longest prefix of 𝑠
 which occurs somewhere else in 𝑠
 as a contiguous substring (the other occurrence may also intersect the prefix). If 𝑥=0
, break. Otherwise, remove the first 𝑥
 characters of 𝑠
, and repeat.
A prefix is a string consisting of several first letters of a given string, without any reorders. An empty prefix is also a valid prefix. For example, the string "abcd" has 5 prefixes: empty string, "a", "ab", "abc" and "abcd".

For instance, if we perform the algorithm on 𝑠=
 "abcabdc",

Initially, "ab" is the longest prefix that also appears somewhere else as a substring in 𝑠
, so 𝑠=
 "cabdc" after 1
 operation.
Then, "c" is the longest prefix that also appears somewhere else as a substring in 𝑠
, so 𝑠=
 "abdc" after 2
 operations.
Now 𝑥=0
 (because there are no non-empty prefixes of "abdc" that also appear somewhere else as a substring in 𝑠
), so the algorithm terminates.
Find the final state of the string after performing the algorithm.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

This is followed by 𝑡
 lines, each containing a description of one test case. Each line contains a string 𝑠
. The given strings consist only of lowercase letters of the English alphabet and have lengths between 1
 and 2⋅105
 inclusive.

It is guaranteed that the sum of the lengths of 𝑠
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single line containing the string 𝑠
 after executing the algorithm. It can be shown that such string is non-empty.

Example
InputCopy
6
abcabdc
a
bbbbbbbbbb
codeforces
cffcfccffccfcffcfccfcffccffcfccf
zyzyzwxxyyxxyyzzyzzxxwzxwywxwzxxyzzw
OutputCopy
abdc
a
b
deforces
cf
xyzzw
Note
The first test case is explained in the statement.

In the second test case, no operations can be performed on 𝑠
.

In the third test case,

Initially, 𝑠=
 "bbbbbbbbbb".
After 1
 operation, 𝑠=
 "b".
In the fourth test case,

Initially, 𝑠=
 "codeforces".
After 1
 operation, 𝑠=
 "odeforces".
After 2
 operations, 𝑠=
 "deforces".


'''
###################################################
###################################################

n=int(input())
for i in range(n):
    s=input()
    l=list(s)
    dictn={}
    for i in l:
        if i not in dictn:
            dictn[i]=1
        else:
            dictn[i]+=1
    left=0
    while dictn[l[left]]>1:
        dictn[l[left]]-=1
        left+=1
    k=(l[left:])
    p="".join(k)
    print(p)