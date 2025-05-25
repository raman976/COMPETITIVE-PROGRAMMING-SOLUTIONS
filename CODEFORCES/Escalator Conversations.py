#############################################
#############################################
'''
A. Escalator Conversations
time limit per test
2 seconds
memory limit per test
256 megabytes

One day, Vlad became curious about who he can have a conversation with on the escalator in the subway. There are a total of n
passengers. The escalator has a total of m steps, all steps indexed from 1 to m and i-th step has height i⋅k

.

Vlad's height is H
centimeters. Two people with heights a and b

can have a conversation on the escalator if they are standing on different steps and the height difference between them is equal to the height difference between the steps.

For example, if two people have heights 170
and 180 centimeters, and m=10,k=5, then they can stand on steps numbered 7 and 5, where the height difference between the steps is equal to the height difference between the two people: k⋅2=5⋅2=10=180−170

. There are other possible ways.

Given an array h
of size n, where hi represents the height of the i

-th person. Vlad is interested in how many people he can have a conversation with on the escalator individually.

For example, if n=5,m=3,k=3,H=11
, and h=[5,4,14,18,2], Vlad can have a conversation with the person with height 5 (Vlad will stand on step 1, and the other person will stand on step 3) and with the person with height 14 (for example, Vlad can stand on step 3, and the other person will stand on step 2). Vlad cannot have a conversation with the person with height 2 because even if they stand on the extreme steps of the escalator, the height difference between them will be 6, while their height difference is 9. Vlad cannot have a conversation with the rest of the people on the escalator, so the answer for this example is 2

.
Input

The first line contains a single integer t
(1≤t≤1000

) — the number of test cases.

Then the descriptions of the test cases follow.

The first line of each test case contains integers: n,m,k,H
(1≤n,m≤50, 1≤k,H≤106). Here, n is the number of people, m is the number of steps, k is the height difference between neighboring steps, and H

is Vlad's height.

The second line contains n
integers: h1,h2,…,hn (1≤hi≤106). Here, hi represents the height of the i

-th person.
Output

For each test case, output a single integer — the number of people Vlad can have a conversation with on the escalator individually.
'''
#############################################
#############################################
t = int(input())
for _ in range(t):
    n, m, k, H = map(int, input().split())
    h = list(map(int, input().split()))
    count = 0
    for hi in h:
        diff = abs(H - hi)
        if diff % k == 0:
            steps_between = diff // k
            if 1 <= steps_between <= m - 1:
                count += 1
    print(count)
