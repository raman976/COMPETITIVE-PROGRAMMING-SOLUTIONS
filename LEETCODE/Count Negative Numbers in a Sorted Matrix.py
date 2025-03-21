################################################################
################################################################
'''
1351. Count Negative Numbers in a Sorted Matrix
Solved
Easy
Topics
Companies
Hint

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 100
    -100 <= grid[i][j] <= 100

 
Follow up: Could you find an O(n + m) solution?
'''
################################################################
'''
link to the problem=====>(https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/)
'''
################################################################
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        def merge(arr1,arr2):
            merged=[]
            i=j=0
            m,n=len(arr1),len(arr2)
            while i<m and j<n:
                if arr1[i]<=arr2[j]:
                    merged.append(arr2[j])
                    j+=1
                else:
                    merged.append(arr1[i])
                    i+=1
            while i<m:
                merged.append(arr1[i])
                i+=1
            while j<n:
                merged.append(arr2[j])
                j+=1 
            return merged
        def mergesort(grid):
            if len(grid)<2:
                return grid[0]
            else:
                merged=merge(grid[0],grid[1])
                for i in range(2,len(grid)):
                    merged=merge(merged,grid[i])
            return merged 
        merged=mergesort(grid)
        print(merged)
        for i in range(len(merged)):
            if merged[i]<0:
                return len(merged)-i
        return 0
