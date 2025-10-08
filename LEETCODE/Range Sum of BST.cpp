// 938. Range Sum of BST
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

// Example 1:

// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

// Example 2:

// Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
// Output: 23
// Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 2 * 104].
//     1 <= Node.val <= 105
//     1 <= low <= high <= 105
//     All Node.val are unique.




class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        
        int sum = 0;
        // If current node value is within range, include it
        if (root->val >= low && root->val <= high)
            sum += root->val;
        
        // If current node's value is greater than low,
        // then left subtree may contain nodes within range
        if (root->val > low)
            sum += rangeSumBST(root->left, low, high);
        
        // If current node's value is less than high,
        // then right subtree may contain nodes within range
        if (root->val < high)
            sum += rangeSumBST(root->right, low, high);
        
        return sum;
    }
};
