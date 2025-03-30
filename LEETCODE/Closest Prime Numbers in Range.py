#######################################################################################
#######################################################################################
'''
2523. Closest Prime Numbers in Range
Solved
Medium
Topics
Companies
Hint

Given two positive integers left and right, find the two integers num1 and num2 such that:

    left <= num1 < num2 <= right .
    Both num1 and num2 are 

    .
    num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.

Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.

Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.

 

Constraints:

    1 <= left <= right <= 106
'''
#######################################################################################
'''
link to the problem====>(https://leetcode.com/problems/closest-prime-numbers-in-range/)
'''
#######################################################################################
class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        def sieve(n):
            is_prime = [True] * (n + 1)
            is_prime[0] = is_prime[1] = False
            for i in range(2, int(n**0.5) + 1):
                if is_prime[i]:
                    for j in range(i * i, n + 1, i):
                        is_prime[j] = False
            return is_prime
        primes = sieve(right)
        prime_list = [i for i in range(left, right + 1) if primes[i]]
        if len(prime_list) < 2:
            return [-1, -1]
        min_diff = float('inf')
        ans = [-1, -1]
        for i in range(len(prime_list) - 1):
            if prime_list[i + 1] - prime_list[i] < min_diff:
                min_diff = prime_list[i + 1] - prime_list[i]
                ans = [prime_list[i], prime_list[i + 1]]
        return ans
    

