##############################################################
##############################################################
'''
B. Squares and Cubes
time limit per test
1 second
memory limit per test
256 megabytes

Polycarp likes squares and cubes of positive integers. Here is the beginning of the sequence of numbers he likes: 1
, 4, 8, 9

, ....

For a given number n
, count the number of integers from 1 to n that Polycarp likes. In other words, find the number of such x that x

is a square of a positive integer number or a cube of a positive integer number (or both a square and a cube simultaneously).
Input

The first line contains an integer t
(1≤t≤20

) — the number of test cases.

Then t
lines contain the test cases, one per line. Each of the lines contains one integer n (1≤n≤109

).
Output

For each test case, print the answer you are looking for — the number of integers from 1
to n

that Polycarp likes.
Example
Input
Copy

6
10
1
25
1000000000
999999999
500000000

Output
Copy

4
1
6
32591
32590
23125
'''
##############################################################
##############################################################
import math

t = int(input())
for _ in range(t):
    n = int(input())
    squares = int(n ** 0.5)
    cubes = int(n ** (1/3))
    sixth_powers = int(n ** (1/6))
    while (cubes + 1) ** 3 <= n:
        cubes += 1
    while cubes ** 3 > n:
        cubes -= 1
    while (sixth_powers + 1) ** 6 <= n:
        sixth_powers += 1
    while sixth_powers ** 6 > n:
        sixth_powers -= 1
    print(squares + cubes - sixth_powers)