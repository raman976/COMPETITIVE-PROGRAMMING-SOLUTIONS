// 1002. Find Common Characters
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

// Example 1:

// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]

// Example 2:

// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]

 

// Constraints:

//     1 <= words.length <= 100
//     1 <= words[i].length <= 100
//     words[i] consists of lowercase English letters.



#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, 0);
        // Initialize freq with the first word
        for (char c : words[0]) {
            freq[c - 'a']++;
        }

        // Update freq with minimum counts from the rest of the words
        for (int i = 1; i < words.size(); i++) {
            vector<int> temp(26, 0);
            for (char c : words[i]) {
                temp[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                freq[j] = min(freq[j], temp[j]);
            }
        }

        // Build the result
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freq[i]; j++) {
                result.push_back(string(1, 'a' + i));
            }
        }

        return result;
    }
};
