// 257. Binary Tree Paths
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.

 

// Example 1:

// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]

// Example 2:

// Input: root = [1]
// Output: ["1"]

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 100].
//     -100 <= Node.val <= 100

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) return paths;
        dfs(root, "", paths);
        return paths;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        if (!node) return;

        // Add current node value to the path
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(node->val);

        // If it's a leaf, add path to result
        if (!node->left && !node->right) {
            paths.push_back(path);
            return;
        }

        // Recurse on left and right
        if (node->left) dfs(node->left, path, paths);
        if (node->right) dfs(node->right, path, paths);
    }
};
