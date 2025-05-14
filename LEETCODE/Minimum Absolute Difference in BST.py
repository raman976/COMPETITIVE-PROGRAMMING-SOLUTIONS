#######################################################################################################
#######################################################################################################
'''
530. Minimum Absolute Difference in BST
Solved
Easy
Topics
Companies

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [2, 104].
    0 <= Node.val <= 105

 

Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
'''
#######################################################################################################
#######################################################################################################

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        sorted_nodes = []
        def inorder(root, lst):
            if root is None:
                return
            inorder(root.left, lst)
            lst.append(root.val)
            inorder(root.right, lst)
        inorder(root, sorted_nodes)
        min_diff = 10**5
        for i in range(len(sorted_nodes)-1):
            min_diff = min(abs(sorted_nodes[i]-sorted_nodes[i+1]),min_diff)
        return min_diff