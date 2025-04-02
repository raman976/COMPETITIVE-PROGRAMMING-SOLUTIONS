#############################################################################################
#############################################################################################
'''
628. Maximum Product of Three Numbers
Solved
Easy
Topics
Companies

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6

Example 2:

Input: nums = [1,2,3,4]
Output: 24

Example 3:

Input: nums = [-1,-2,-3]
Output: -6

 

Constraints:

    3 <= nums.length <= 104
    -1000 <= nums[i] <= 1000
'''
#############################################################################################
#############################################################################################


class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()
        nums.reverse()
        k1=nums[0]*nums[1]*nums[2]
        k2=nums[0]*nums[-1]*nums[-2]
        if k1>k2:
            return k1
        else:
            return k2