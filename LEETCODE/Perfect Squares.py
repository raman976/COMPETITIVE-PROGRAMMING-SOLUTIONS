#######################################################################################################
#######################################################################################################
'''
279. Perfect Squares
Solved
Medium
Topics
Companies

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

 

Constraints:

    1 <= n <= 104
'''
#######################################################################################################
#######################################################################################################

class Solution:
    def numSquares(self, n: int) -> int:
        N=n
        dp = [float('inf')] * (N + 1)
        dp[0] = 0
        squares = [i * i for i in range(1, int(N**0.5) + 1)]
        for i in range(1, N + 1):
            for sq in squares:
                if i < sq:
                    break
                dp[i] = min(dp[i], dp[i - sq] + 1)
        return dp[N]