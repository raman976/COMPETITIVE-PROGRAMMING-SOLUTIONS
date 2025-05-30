###############################################################
###############################################################
'''
441. Arranging Coins
Solved
Easy
Topics
Companies

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

 

Example 1:

Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.

Example 2:

Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.

 

Constraints:

    1 <= n <= 231 - 1


'''
###############################################################
###############################################################

class Solution:
    def arrangeCoins(self, n: int) -> int:
        left=1
        right=n
        possible=1
        while left<=right:
            mid=(left+right)//2
            if mid*(mid+1)//2==n:
                return mid
            elif (mid)*(mid+1)//2>n:
                right=mid-1
            else:
                left=mid+1
                possible=mid
        return possible