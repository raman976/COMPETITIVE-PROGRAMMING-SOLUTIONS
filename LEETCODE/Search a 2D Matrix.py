#################################################
#################################################
'''
74. Search a 2D Matrix
Solved
Medium
Topics
Companies

You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104


'''
#################################################
#################################################


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        low = 0
        high = len(matrix) - 1
        while low <= high:
            mid = (low + high) // 2
            if matrix[mid][0] <= target <= matrix[mid][-1]:
                left = 0
                right = len(matrix[mid]) - 1
                while left <= right:
                    mid2 = (left + right) // 2
                    if matrix[mid][mid2] < target:
                        left = mid2 + 1
                    elif matrix[mid][mid2] > target:
                        right = mid2 - 1
                    else:
                        return True
                return False
            elif matrix[mid][-1] < target:
                low = mid + 1
            else:
                high = mid - 1
        return False