##########################################################################
##########################################################################
'''
4. Median of Two Sorted Arrays
Solved
Hard
Topics
Companies

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

 

Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106
'''
##########################################################################
'''
link to the problem=====>(https://leetcode.com/problems/median-of-two-sorted-arrays/description/)
'''
##########################################################################

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def merge(nums1,num2):
            i,j=0,0
            m,n=len(nums1),len(nums2)
            merged=[]
            while i<m and j<n:
                if nums1[i]<nums2[j]:
                    merged.append(nums1[i])
                    i+=1
                else:
                    merged.append(nums2[j])
                    j+=1
            while i<m:
                merged.append(nums1[i])
                i+=1
            while j<n:
                merged.append(nums2[j])
                j+=1
            return merged
        merged=merge(nums1,nums2)
        k=len(merged)
        if k%2==0:
            median=(merged[k//2]+merged[(k//2)-1])/2
        else:
            median=(merged[k//2])
        return median
        
            