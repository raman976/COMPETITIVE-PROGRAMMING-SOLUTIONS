###################################################
###################################################
'''
540. Single Element in a Sorted Array
Solved
Medium
Topics
Companies

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

 

Constraints:

    1 <= nums.length <= 105
    0 <= nums[i] <= 105
'''
###################################################
###################################################

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        if nums[len(nums)-1]!=nums[len(nums)-2]:
            return nums[len(nums)-1]
        if nums[0]!=nums[1]:
            return nums[0]
        left=1
        arr=nums
        right=len(nums)-2
        while left<=right:
            mid=(left+right)//2
            if arr[mid]!=arr[mid+1] and arr[mid]!=arr[mid-1]:
                return arr[mid]
            if (mid%2==0 and arr[mid]==arr[mid+1]) or (mid%2==1 and arr[mid]==arr[mid-1]):
                left=mid+1
            else:
                right=mid-1
        