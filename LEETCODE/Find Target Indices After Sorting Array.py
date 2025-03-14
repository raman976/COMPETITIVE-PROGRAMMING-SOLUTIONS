##############################################################################
##############################################################################
'''
2089. Find Target Indices After Sorting Array
Solved
Easy
Topics
Companies
Hint

You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

 

Example 1:

Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.

Example 2:

Input: nums = [1,2,5,2,3], target = 3
Output: [3]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 3 is 3.

Example 3:

Input: nums = [1,2,5,2,3], target = 5
Output: [4]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 5 is 4.

 

Constraints:

    1 <= nums.length <= 100
    1 <= nums[i], target <= 100
'''
##############################################################################
##############################################################################

class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        first=-1
        left1=0
        right1=len(nums)-1
        while left1<=right1:
            mid=(left1+right1)//2
            if nums[mid]>target:
                right1=mid-1
            elif nums[mid]<target:
                left1=mid+1
            else:
                right1=mid-1
                first=mid
        last=-1
        left2=0
        right2=len(nums)-1
        while left2<=right2:
            mid=(left2+right2)//2
            if nums[mid]>target:
                right2=mid-1
            elif nums[mid]<target:
                left2=mid+1
            else:
                left2=mid+1
                last=mid
        if first==-1 or last==-1:
            return []
        if first==last:
            return [first]
        l=[]
        for i in range(first,last+1):
            l.append(i)
        return l
        