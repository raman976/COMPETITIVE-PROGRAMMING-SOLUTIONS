// 131. Palindrome Partitioning
// Solved
// Medium
// Topics
// premium lock iconCompanies

// Given a string s, partition s such that every
// of the partition is a

// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// Example 2:

// Input: s = "a"
// Output: [["a"]]

 

// Constraints:

//     1 <= s.length <= 16
//     s contains only lowercase English letters.

 
class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(0, s, path);
        return res;
    }

    void dfs(int start, string &s, vector<string> &path) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, s, path);
                path.pop_back(); 
            }
        }
    }

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
