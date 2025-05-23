######################################################
######################################################
'''
A. Trippi Troppi
time limit per test
1 second
memory limit per test
256 megabytes

Trippi Troppi resides in a strange world. The ancient name of each country consists of three strings. The first letter of each string is concatenated to form the country's modern name.

Given the country's ancient name, please output the modern name.
Input

The first line contains an integer t
 – the number of independent test cases (1≤t≤100

).

The following t
lines each contain three space-separated strings. Each string has a length of no more than 10

, and contains only lowercase Latin characters.
Output

For each test case, output the string formed by concatenating the first letter of each word.
Example
Input
Copy

7
united states america
oh my god
i cant lie
binary indexed tree
believe in yourself
skibidi slay sigma
god bless america

Output
Copy

usa
omg
icl
bit
biy
sss
gba
'''
######################################################
######################################################

n = int(input()) 
for _ in range(n):
    parts = input().split()
    short_name = ''.join(p[0] for p in parts)
    print(short_name)