###############################################################
###############################################################
'''
B1. Wonderful Coloring - 1
time limit per test
1 second
memory limit per test
256 megabytes

This is a simplified version of the problem B2. Perhaps you should read the problem B2 before you start solving B1.

Paul and Mary have a favorite string s

which consists of lowercase letters of the Latin alphabet. They want to paint it using pieces of chalk of two colors: red and green. Let's call a coloring of a string wonderful if the following conditions are met:

    each letter of the string is either painted in exactly one color (red or green) or isn't painted;
    each two letters which are painted in the same color are different;
    the number of letters painted in red is equal to the number of letters painted in green;
    the number of painted letters of this coloring is maximum among all colorings of the string which meet the first three conditions. 

E. g. consider a string s

equal to "kzaaa". One of the wonderful colorings of the string is shown in the figure.
The example of a wonderful coloring of the string "kzaaa".

Paul and Mary want to learn by themselves how to find a wonderful coloring of the string. But they are very young, so they need a hint. Help them find k

— the number of red (or green, these numbers are equal) letters in a wonderful coloring.
Input

The first line contains one integer t
(1≤t≤1000) — the number of test cases. Then t

test cases follow.

Each test case consists of one non-empty string s
which consists of lowercase letters of the Latin alphabet. The number of characters in the string doesn't exceed 50

.
Output

For each test case, output a separate line containing one non-negative integer k

— the number of letters which will be painted in red in a wonderful coloring.
Example
Input
Copy

5
kzaaa
codeforces
archive
y
xxxxxx

Output
Copy

2
5
3
0
1

Note

The first test case contains the string from the statement. One of the wonderful colorings is shown in the figure. There's no wonderful coloring containing 3

or more red letters because the total number of painted symbols will exceed the string's length.

The string from the second test case can be painted as follows. Let's paint the first occurrence of each of the letters "c", "o", "e" in red and the second ones in green. Let's paint the letters "d", "f" in red and "r", "s" in green. So every letter will be painted in red or green, hence the answer better than 5

doesn't exist.

The third test case contains the string of distinct letters, so you can paint any set of characters in red, as long as the size of this set doesn't exceed half of the size of the string and is the maximum possible.

The fourth test case contains a single letter which cannot be painted in red because there will be no letter able to be painted in green.

The fifth test case contains a string of identical letters, so there's no way to paint more than one letter in red.
'''
###############################################################
###############################################################
t = int(input())
for _ in range(t):
    s = input()
    freq = [0] * 26
    for ch in s:
        freq[ord(ch) - ord('a')] += 1
    count_2_or_more = 0
    count_once = 0
    for f in freq:
        if f >= 2:
            count_2_or_more += 1
        elif f == 1:
            count_once += 1
    print(count_2_or_more + (count_once // 2))
