###################################################################
###################################################################
'''
1636. Sort Array by Increasing Frequency
Solved
Easy
Topics
Companies
Hint

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]

 

Constraints:

    1 <= nums.length <= 100
    -100 <= nums[i] <= 100
'''
###################################################################
'''
link to the problem=============>(https://leetcode.com/problems/sort-array-by-increasing-frequency/description/)
'''
###################################################################

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        dictn={}
        for i in nums:
            if i not in dictn:
                dictn[i]=1
            else:
                dictn[i]+=1
        print(dictn)
        for i in range(len(nums)):
            for j in range(len(nums)-1-i):
                if dictn[nums[j]]>dictn[nums[j+1]]:
                    nums[j],nums[j+1]=nums[j+1],nums[j]
                if dictn[nums[j]]==dictn[nums[j+1]]:
                    if nums[j]<nums[j+1]:
                        nums[j],nums[j+1]=nums[j+1],nums[j]
        return nums