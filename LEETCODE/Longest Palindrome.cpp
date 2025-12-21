// 409. Longest Palindrome
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest

//  that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

// Example 2:

// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.

 

// Constraints:

//     1 <= s.length <= 2000
//     s consists of lowercase and/or uppercase English letters only.

 


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        
        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }
        
        int length = 0;
        bool hasOdd = false;
        
        // Build the palindrome length
        for (auto &p : freq) {
            length += (p.second / 2) * 2;  // add largest even part
            if (p.second % 2 == 1) {
                hasOdd = true;
            }
        }
        
        // One odd character can be placed in the center
        if (hasOdd) {
            length += 1;
        }
        
        return length;
    }
};
