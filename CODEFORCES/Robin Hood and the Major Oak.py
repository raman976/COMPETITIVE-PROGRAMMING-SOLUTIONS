#############################################################
#############################################################
'''
B. Robin Hood and the Major Oak
time limit per test
1 second
memory limit per test
256 megabytes
In Sherwood, the trees are our shelter, and we are all children of the forest.

The Major Oak in Sherwood is known for its majestic foliage, which provided shelter to Robin Hood and his band of merry men and women.

The Major Oak grows ii
new leaves in the i-th year. It starts with 1 leaf in year 1

.

Leaves last for k
years on the tree. In other words, leaves grown in year i last between years i and i+k−1

inclusive.

Robin considers even numbers lucky. Help Robin determine whether the Major Oak will have an even number of leaves in year n

.
Input

The first line of the input contains a single integer t
(1≤t≤104

) — the number of test cases.

Each test case consists of two integers n
, k (1≤n≤109, 1≤k≤n

) — the requested year and the number of years during which the leaves remain.
Output

For each test case, output one line, "YES" if in year n

the Major Oak will have an even number of leaves and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
Example
Input
Copy

5
1 1
2 1
2 2
3 2
4 4

Output
Copy

NO
YES
NO
NO
YES

Note

In the first test case, there is only 1

leaf.

In the second test case, k=1
, so in the 2-nd year there will be 22=4

leaves.

In the third test case, k=2
, so in the 2-nd year there will be 1+22=5

leaves.

In the fourth test case, k=2
, so in the 3-rd year there will be 22+33=4+27=31

leaves.
'''
#############################################################
#############################################################
t=int(input())
for x in range(t):
    n,k=map(int,input().split())
    start=n-k+1
    end=n
    odd=(end+1)//2-(start)//2
    if odd%2==0:
        print("YES")
    else:
        print("NO")
