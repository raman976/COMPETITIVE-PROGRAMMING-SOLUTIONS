############################################
"""
############################################
A. Elephant
time limit per test
1 second
memory limit per test
256 megabytes

An elephant decided to visit his friend. It turned out that the elephant's house is located at point 0 and his friend's house is located at point x(x > 0) of the coordinate line. In one step the elephant can move 1, 2, 3, 4 or 5 positions forward. Determine, what is the minimum number of steps he need to make in order to get to his friend's house.
Input

The first line of the input contains an integer x (1 ≤ x ≤ 1 000 000) — The coordinate of the friend's house.
Output

Print the minimum number of steps that elephant needs to make to get from point 0 to point x.
Examples
Input
Copy

5

Output
Copy

1

Input
Copy

12

Output
Copy

3

Note

In the first sample the elephant needs to make one step of length 5 to reach the point x.

In the second sample the elephant can get to point x if he moves by 3, 5 and 4. There are other ways to get the optimal answer but the elephant cannot reach x in less than three moves.
############################################
"""
############################################

n=int(input())
steps=0
while n!=0:
    if n>=5:
        steps+=n//5
        n=n%5
    elif n>=4:
        steps+=n//4
        n=n%4
    elif n>=3:
        steps+=n//3
        n=n%3
    elif n>=2:
        steps+=n//2
        n=n%2
    elif n>=1:
        steps+=n//1
        n=n%1
print(steps)