# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def max_spread(root):
            if not root:
                return 0

            m = -100000000
            a = [(root, 0)] 
            while a:
                s = []
                start = a[0][1]
                end = a[-1][1]
                m = max(m, end - start + 1)

                for i in range(len(a)):
                    node, idx = a[i]
                    if node.left:
                        s.append((node.left, 2 * idx))
                    if node.right:
                        s.append((node.right, 2 * idx + 1))

                a = s

            return m
        return max_spread(root)