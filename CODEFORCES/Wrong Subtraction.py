####################################
'''
####################################
A. Wrong Subtraction
time limit per test
1 second
memory limit per test
256 megabytes

Little girl Tanya is learning how to decrease a number by one, but she does it wrong with a number consisting of two or more digits. Tanya subtracts one from a number by the following algorithm:

    if the last digit of the number is non-zero, she decreases the number by one;
    if the last digit of the number is zero, she divides the number by 10 (i.e. removes the last digit). 

You are given an integer number n
. Tanya will subtract one from it k times. Your task is to print the result after all k

subtractions.

It is guaranteed that the result will be positive integer number.
Input

The first line of the input contains two integer numbers n
and k (2≤n≤109, 1≤k≤50

) — the number from which Tanya will subtract and the number of subtractions correspondingly.
Output

Print one integer number — the result of the decreasing n
by one k

times.

It is guaranteed that the result will be positive integer number.
Examples
Input
Copy

512 4

Output
Copy

50

Input
Copy

1000000000 9

Output
Copy

1

Note

The first example corresponds to the following sequence: 512→511→510→51→50
####################################
'''
####################################

a,b=map(int,input().split())
for i in range(b):
    if a%10==0:
        a=a//10
    else:
        a=a-1
print(a)