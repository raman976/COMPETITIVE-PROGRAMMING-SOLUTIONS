// 5. Longest Palindromic Substring
// Solved
// Medium
// Topics
// premium lock iconCompanies
// Hint

// Given a string s, return the longest

// in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:

// Input: s = "cbbd"
// Output: "bb"

 

// Constraints:

//     1 <= s.length <= 1000
//     s consist of only digits and English letters.




class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        // Helper lambda to expand around center
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    start = left;
                    maxLen = len;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);     // Odd-length palindrome
            expand(i, i + 1); // Even-length palindrome
        }

        return s.substr(start, maxLen);
    }
};
