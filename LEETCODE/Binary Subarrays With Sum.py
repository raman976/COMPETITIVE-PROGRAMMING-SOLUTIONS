####################################################
####################################################
'''
930. Binary Subarrays With Sum
Solved
Medium
Topics
Companies

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15

 

Constraints:

    1 <= nums.length <= 3 * 104
    nums[i] is either 0 or 1.
    0 <= goal <= nums.length
'''
####################################################
####################################################

class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        arr=[]
        k=goal
        for i in nums:
            if i%2==1:
                arr.append(1)
            else:
                arr.append(0)
        def f(arr,k,l,r,s,count):
            if k<0:
                return 0
            for r in range(len(arr)):
                s+=arr[r]
                while s>k:
                    s-=arr[l]
                    l+=1
                count+=(r-l+1)
            return count 
        return f(arr,k,0,0,0,0)-f(arr,k-1,0,0,0,0)
            