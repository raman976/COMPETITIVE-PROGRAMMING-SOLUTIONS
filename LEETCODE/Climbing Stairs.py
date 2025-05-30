#####################################################################################################
#####################################################################################################
'''
70. Climbing Stairs
Solved
Easy
Topics
Companies
Hint

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

 

Constraints:

    1 <= n <= 45
'''
#####################################################################################################
'''
link to the problem=====>(https://leetcode.com/problems/climbing-stairs/description/)
'''
#####################################################################################################


class Solution:
    def climbStairs(self, n: int) -> int:
        dictn={}
        def f(n,ind):
            if ind in dictn:
                return dictn[ind]
            if ind>n:
                return 0
            if ind==n:
                return 1
            else:
                dictn[ind]=f(n,ind+1)+f(n,ind+2)
                return dictn[ind]
        return f(n,0)