##################################################################
##################################################################
'''
A. Dislike of Threes
time limit per test
1 second
memory limit per test
256 megabytes

Polycarp doesn't like integers that are divisible by 3
or end with the digit 3

in their decimal representation. Integers that meet both conditions are disliked by Polycarp, too.

Polycarp starts to write out the positive (greater than 0
) integers which he likes: 1,2,4,5,7,8,10,11,14,16,…. Output the k-th element of this sequence (the elements are numbered from 1

).
Input

The first line contains one integer t
(1≤t≤100) — the number of test cases. Then t

test cases follow.

Each test case consists of one line containing one integer k
(1≤k≤1000

).
Output

For each test case, output in a separate line one integer x
— the k

-th element of the sequence that was written out by Polycarp.
Example
Input
Copy

10
1
2
3
4
5
6
7
8
9
1000

Output
Copy

1
2
4
5
7
8
10
11
14
1666
'''
##################################################################
'''
link to the problem=====>(https://codeforces.com/problemset/problem/1560/A)
'''
##################################################################

def disliked_numbers():
    liked=[]
    num=1
    while len(liked)< 1000:
        if num % 3!=0 and num % 10 != 3:
            liked.append(num)
        num += 1
    return liked
def solve():
    liked = disliked_numbers()
    t = int(input()) 
    for o in range(t):
        k = int(input()) 
        print(liked[k - 1]) 
solve()
