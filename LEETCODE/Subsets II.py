######################################################
######################################################
'''
90. Subsets II
Solved
Medium
Topics
Companies

Given an integer array nums that may contain duplicates, return all possible

(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

 

Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
'''
######################################################
######################################################

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        big=[]
        nums.sort()
        def f(nums,ind,new):
            if ind==len(nums):
                big.append(new)
                return big
            else:
                case1=f(nums,ind+1,new+[nums[ind]])
                while ind+1<len(nums) and nums[ind]==nums[ind+1]:
                    ind+=1
                case2=f(nums,ind+1,new)
            return big
        a=f(nums,0,[])
        return a