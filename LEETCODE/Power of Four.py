##########################################################################
##########################################################################
'''
342. Power of Four
Solved
Easy
Topics
Companies

Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true

Example 2:

Input: n = 5
Output: false

Example 3:

Input: n = 1
Output: true

 

Constraints:

    -231 <= n <= 231 - 1

 
Follow up: Could you solve it without loops/recursion?

'''
##########################################################################
##########################################################################


class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        def f(k):
            if k==1:
                return True
            if k==0:
                return False
            elif k<0 or k%4!=0:
                return False
            else:
                return f(k//4)
        return (f(n))