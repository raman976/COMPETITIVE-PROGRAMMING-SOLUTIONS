####################################################
####################################################
'''
A. Creating Words
time limit per test
1 second
memory limit per test
256 megabytes

Matthew is given two strings a
and b, both of length 3. He thinks it's particularly funny to create two new words by swapping the first character of a with the first character of b. He wants you to output a and b

after the swap.

Note that the new words may not necessarily be different.
Input

The first line contains t
(1≤t≤100

)  — the number of test cases.

The first and only line of each test case contains two space-separated strings, a
and b, both of length 3

. The strings only contain lowercase Latin letters.
Output

For each test case, after the swap, output a
and b

, separated by a space.
Example
Input
Copy

6
bit set
cat dog
hot dog
uwu owo
cat cat
zzz zzz

Output
Copy

sit bet
dat cog
dot hog
owu uwo
cat cat
zzz zzz

A. Creating Words
time limit per test
1 second
memory limit per test
256 megabytes

Matthew is given two strings a
and b, both of length 3. He thinks it's particularly funny to create two new words by swapping the first character of a with the first character of b. He wants you to output a and b

after the swap.

Note that the new words may not necessarily be different.
Input

The first line contains t
(1≤t≤100

)  — the number of test cases.

The first and only line of each test case contains two space-separated strings, a
and b, both of length 3

. The strings only contain lowercase Latin letters.
Output

For each test case, after the swap, output a
and b

, separated by a space.
Example
Input
Copy

6
bit set
cat dog
hot dog
uwu owo
cat cat
zzz zzz

Output
Copy

sit bet
dat cog
dot hog
owu uwo
cat cat
zzz zzz
'''
####################################################
####################################################
n=int(input())
for i in range(n):
    a,b=map(str,input().split())
    x=a[0]
    y=b[0]
    p=list(a)
    q=list(b)
    p[0]=y
    q[0]=x
    p="".join(p)
    q="".join(q)
    print(f"{p} {q}")

    