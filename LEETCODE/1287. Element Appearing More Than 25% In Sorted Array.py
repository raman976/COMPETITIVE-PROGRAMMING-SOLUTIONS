####################################################################
####################################################################
'''
1287. Element Appearing More Than 25% In Sorted Array
Solved
Easy
Topics
Companies
Hint

Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

Example 2:

Input: arr = [1,1]
Output: 1

 

Constraints:

    1 <= arr.length <= 104
    0 <= arr[i] <= 105


'''
####################################################################
'''
link to the problem=====>(https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/)
'''
####################################################################

class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        def find_special_integer(arr):
            def first_and_last(k):
                first=0
                left=0
                right=len(arr)-1
                while left<=right:
                    mid=(left+right)//2
                    if arr[mid]==k:
                        right=mid-1
                        first=mid
                    elif arr[mid]<k:
                        left=mid+1
                    else:
                        right=mid-1
                last=0
                left=0
                right=len(arr)-1
                while left<=right:
                    mid=(left+right)//2
                    if arr[mid]==k:
                        left=mid+1
                        last=mid
                    elif arr[mid]<k:
                        left=mid+1
                    else:
                        right=mid-1
                return [first,last]
            setn=set(arr)
            for i in setn:
                a,b=first_and_last(i)
                if (b-a+1)>len(arr)//4:
                    return i
        return find_special_integer(arr)    