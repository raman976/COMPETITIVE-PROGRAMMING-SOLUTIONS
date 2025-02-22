############################################
############################################
'''
B. Good Kid
time limit per test
1 second
memory limit per test
256 megabytes

Slavic is preparing a present for a friend's birthday. He has an array a
of n digits and the present will be the product of all these digits. Because Slavic is a good kid who wants to make the biggest product possible, he wants to add 1

to exactly one of his digits.

What is the maximum product Slavic can make?
Input

The first line contains a single integer t
(1≤t≤104

) — the number of test cases.

The first line of each test case contains a single integer n
(1≤n≤9

) — the number of digits.

The second line of each test case contains n
space-separated integers ai (0≤ai≤9

) — the digits in the array.
Output

For each test case, output a single integer — the maximum product Slavic can make, by adding 1

to exactly one of his digits.
Example
Input
Copy

4
4
2 2 1 2
3
0 1 2
5
4 3 2 3 4
9
9 9 9 9 9 9 9 9 9

Output
Copy

16
2
432
430467210


'''
############################################
############################################


n=int(input())
for i in range(n):
    p=int(input())
    l=list(map(int,input().split()))
    pro=1
    count=0
    for i in range(len(l)):  
        if l[i]==min(l) and count==0:
            pro*=(l[i]+1)
            count+=1
        else:
            pro*=l[i]
    print(pro)
    