// 1160. Find Words That Can Be Formed by Characters
// Solved
// Easy
// Topics
// premium lock iconCompanies
// Hint

// You are given an array of strings words and a string chars.

// A string is good if it can be formed by characters from chars (each character can only be used once for each word in words).

// Return the sum of lengths of all good strings in words.

 

// Example 1:

// Input: words = ["cat","bt","hat","tree"], chars = "atach"
// Output: 6
// Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

// Example 2:

// Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
// Output: 10
// Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

 

// Constraints:

//     1 <= words.length <= 1000
//     1 <= words[i].length, chars.length <= 100
//     words[i] and chars consist of lowercase English letters.




class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        
        // Count chars frequency
        for (char c : chars) {
            freq[c - 'a']++;
        }
        
        int totalLength = 0;
        
        // Check each word
        for (const string& word : words) {
            vector<int> f = freq;
            bool good = true;
            
            for (char c : word) {
                if (--f[c - 'a'] < 0) {
                    good = false;
                    break;
                }
            }
            
            if (good) totalLength += word.size();
        }
        
        return totalLength;
    }
};
