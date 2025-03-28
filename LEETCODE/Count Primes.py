#####################################################################
#####################################################################
'''
204. Count Primes
Solved
Medium
Topics
Companies
Hint

Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0

 

Constraints:

    0 <= n <= 5 * 106
'''
#####################################################################
'''link to the problem=====>(https://leetcode.com/problems/count-primes/description/)'''
#####################################################################

class Solution:
    def countPrimes(self, n: int) -> int:
        p=[True]*(n+1)
        if n==0:
            return 0
        p[0]=p[1]=False
        for i in range(2,int(n**0.5)+1):
            for j in range(i*i,n+1,i):
                p[j]=False
        if p[n]==True:
            return sum(p)-1
        return sum(p)



