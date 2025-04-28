###################################################################
###################################################################
'''
199. Binary Tree Right Side View
Solved
Medium
Topics
Companies

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:

Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:

Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
'''
###################################################################
###################################################################

from collections import deque
from typing import Optional, List

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional['TreeNode']) -> List[int]:
        if not root:
            return []
        
        result = []
        queue = deque([root])

        while queue:
            level_size = len(queue)
            for i in range(level_size):
                node = queue.popleft()
                if i == level_size - 1:
                    result.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        
        return result

def build_tree(level_order_str):
    nodes = level_order_str.split()
    if not nodes or nodes[0] == "N":
        return None

    root = TreeNode(int(nodes[0]))
    queue = deque([root])
    i = 1

    while queue and i < len(nodes):
        node = queue.popleft()

        if nodes[i] != "N":
            node.left = TreeNode(int(nodes[i]))
            queue.append(node.left)
        i += 1

        if i < len(nodes) and nodes[i] != "N":
            node.right = TreeNode(int(nodes[i]))
            queue.append(node.right)
        i += 1

    return root
