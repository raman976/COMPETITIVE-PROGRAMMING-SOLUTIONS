###########################################################################
###########################################################################
'''
A. Vlad and the Best of Five
time limit per test
1 second
memory limit per test
256 megabytes

Vladislav has a string of length 5
, whose characters are each either A or B

.

Which letter appears most frequently: A
or B

?
Input

The first line of the input contains an integer t
(1≤t≤32

) — the number of test cases.

The only line of each test case contains a string of length 5
consisting of letters A and B

.

All t

strings in a test are different (distinct).
Output

For each test case, output one letter (A
or B

) denoting the character that appears most frequently in the string.
Example
Input
Copy

8
ABABB
ABABA
BBBAB
AAAAA
BBBBB
BABAA
AAAAB
BAAAA

Output
Copy

B
A
B
A
B
A
A
A
'''
###########################################################################
###########################################################################

n=int(input())
for i in range(n):
    s=input()
    a=s.count("A")
    b=s.count("B")
    if a>b:
        print("A")
    else:
        print("B")