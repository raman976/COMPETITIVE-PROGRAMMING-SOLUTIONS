"""
A. Fibonacciness
time limit per test
1 second
memory limit per test
256 megabytes

There is an array of 5
integers. Initially, you only know a1,a2,a4,a5. You may set a3 to any positive integer, negative integer, or zero. The Fibonacciness of the array is the number of integers i (1≤i≤3) such that ai+2=ai+ai+1. Find the maximum Fibonacciness over all integer values of a3

.
Input

The first line contains an integer t
(1≤t≤500

) — the number of test cases.

The only line of each test case contains four integers a1,a2,a4,a5
(1≤ai≤100

).
Output

For each test case, output the maximum Fibonacciness on a new line.
Example
Input
Copy

6
1 1 3 5
1 3 2 1
8 10 28 100
100 1 100 1
1 100 1 100
100 100 100 100

Output
Copy

3
2
2
1
1
2

Note

In the first test case, we can set a3
to 2 to achieve the maximal Fibonacciness of 3

.

In the third test case, it can be shown that 2
is the maximum Fibonacciness that can be achieved. This can be done by setting a3 to 18

.


"""
t=int(input())
for i in range(t):
    l=list(map(int,input().split()))
    a=[]
    a.append(l[0]+l[1])
    a.append(l[2]-l[1])
    a.append(l[3]-l[2])
    dictn={}
    p=[]
    for i in a:
        if i not in dictn:
            dictn[i]=1
        else:
            dictn[i]+=1
    for i in dictn:
        p.append(dictn[i])
    print(max(p))
