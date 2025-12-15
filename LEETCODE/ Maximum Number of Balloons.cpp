// 1189. Maximum Number of Balloons
// Solved
// Easy
// Topics
// premium lock iconCompanies
// Hint

// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

// Example 1:

// Input: text = "nlaebolko"
// Output: 1

// Example 2:

// Input: text = "loonbalxballpoon"
// Output: 2

// Example 3:

// Input: text = "leetcode"
// Output: 0

 

// Constraints:

//     1 <= text.length <= 104
//     text consists of lower case English letters only.

 

// Note: This question is the same as 2287: Rearrange Characters to Make Target String.
 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 3,08,080/514.7K
// Acceptance Rate
// 59.9%




class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char c : text) {
            freq[c - 'a']++;
        }

        // Compute the maximum number of "balloon"
        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};
