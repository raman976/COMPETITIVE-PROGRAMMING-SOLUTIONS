// 111. Minimum Depth of Binary Tree
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

 

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 2

// Example 2:

// Input: root = [2,null,3,null,4,null,5,null,6]
// Output: 5

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 105].
//     -1000 <= Node.val <= 1000

 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 15,69,942/3M
// Acceptance Rate
// 51.8%



class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        // If left subtree is missing, go right
        if (!root->left) 
            return 1 + minDepth(root->right);

        // If right subtree is missing, go left
        if (!root->right) 
            return 1 + minDepth(root->left);

        // Both children exist, take the minimum
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
