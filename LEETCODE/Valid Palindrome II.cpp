// 680. Valid Palindrome II
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

// Example 1:

// Input: s = "aba"
// Output: true

// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:

// Input: s = "abc"
// Output: false

 

// Constraints:

//     1 <= s.length <= 105
//     s consists of lowercase English letters.

 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 10,35,538/2.4M
// Acceptance Rate
// 43.5%
// Topics
// Two Pointers
// String
// Greedy



class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                // Try skipping left or right character
                return isPalindromeRange(s, left + 1, right) || isPalindromeRange(s, left, right - 1);
            }
        }
        
        return true;
    }
    
private:
    bool isPalindromeRange(const string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
