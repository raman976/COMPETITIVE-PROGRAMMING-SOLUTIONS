################################################################
################################################################
'''
A. Cakeminator
time limit per test
1 second
memory limit per test
256 megabytes

You are given a rectangular cake, represented as an r × c grid. Each cell either has an evil strawberry, or is empty. For example, a 3 × 4 cake may look as follows:

The cakeminator is going to eat the cake! Each time he eats, he chooses a row or a column that does not contain any evil strawberries and contains at least one cake cell that has not been eaten before, and eats all the cake cells there. He may decide to eat any number of times.

Please output the maximum number of cake cells that the cakeminator can eat.
Input

The first line contains two integers r and c (2 ≤ r, c ≤ 10), denoting the number of rows and the number of columns of the cake. The next r lines each contains c characters — the j-th character of the i-th line denotes the content of the cell at row i and column j, and is either one of these:

    '.' character denotes a cake cell with no evil strawberry;
    'S' character denotes a cake cell with an evil strawberry. 

Output

Output the maximum number of cake cells that the cakeminator can eat.
Examples
Input
Copy

3 4
S...
....
..S.

Output
Copy

8

Note

For the first example, one possible way to eat the maximum number of cake cells is as follows (perform 3 eats).
'''
################################################################
################################################################
r, c = map(int, input().split())
cake = [list(input()) for _ in range(r)]
eaten = [[False]*c for _ in range(r)]
count = 0
for i in range(r):
    if 'S' not in cake[i]:
        for j in range(c):
            if not eaten[i][j]:
                eaten[i][j] = True
                count += 1
for j in range(c):
    if all(cake[i][j] != 'S' for i in range(r)):
        for i in range(r):
            if not eaten[i][j]:
                eaten[i][j] = True
                count += 1
print(count)
