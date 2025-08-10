// 501. Find Mode in Binary Search Tree
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

// If the tree has more than one mode, return them in any order.

// Assume a BST is defined as follows:

//     The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//     The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//     Both the left and right subtrees must also be binary search trees.

 

// Example 1:

// Input: root = [1,null,2,2]
// Output: [2]

// Example 2:

// Input: root = [0]
// Output: [0]

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 104].
//     -105 <= Node.val <= 105

 
// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).



class Solution {
public:
    vector<int> modes;
    int maxCount = 0;
    int currCount = 0;
    int prevVal = INT_MIN; 
    bool hasPrev = false; // to handle the first node

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (hasPrev && root->val == prevVal) {
            currCount++;
        } else {
            currCount = 1;
            prevVal = root->val;
            hasPrev = true;
        }

        if (currCount > maxCount) {
            maxCount = currCount;
            modes.clear();
            modes.push_back(root->val);
        } else if (currCount == maxCount) {
            modes.push_back(root->val);
        }

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};
