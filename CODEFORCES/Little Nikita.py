#########################################################################################
#########################################################################################
'''
A. Little Nikita
time limit per test
1 second
memory limit per test
256 megabytes

The little boy Nikita was given some cubes as a present. He decided to build a tower out of them.

Initially, the tower doesn't have any cubes. In one move, Nikita either puts exactly 1
cube on top of the tower or removes exactly 1 cube from the top of the tower. Is it possible that after n moves, the resulting tower has exactly m

cubes?
Input

Each test contains multiple test cases. The first line of input contains a single integer t
(1≤t≤100

) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers n
and m (1≤n,m≤100

).
Output

For each test case, output "Yes" (without quotes) if Nikita can obtain a tower with m

cubes, and "No" (without quotes) otherwise.

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.
Example
Input
Copy

3
3 3
2 4
5 3

Output
Copy

Yes
No
Yes

Note

In the first test case, Nikita can put 1
cube on top of the tower 3

times in a row, so the answer is "Yes".

In the second test case, Nikita can only end up with either a tower with no blocks or a tower with 2

blocks, so the answer is "No".
'''
#########################################################################################
#########################################################################################
def can_build_tower(n, m):
    return (0 <= m <= n) and ((n - m) % 2 == 0)
def solve():
    t = int(input()) 
    for _ in range(t):
        n, m = map(int, input().split())  
        if can_build_tower(n, m):
            print("Yes")
        else:
            print("No")
solve()
