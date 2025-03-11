##################################################################
##################################################################
'''
1248. Count Number of Nice Subarrays
Solved
Medium
Topics
Companies
Hint

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

 

Constraints:

    1 <= nums.length <= 50000
    1 <= nums[i] <= 10^5
    1 <= k <= nums.length
'''
##################################################################
##################################################################

class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        arr=[]
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
            