// 796. Rotate String
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

//     For example, if s = "abcde", then it will be "bcdea" after one shift.

 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true

// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false

 

// Constraints:

//     1 <= s.length, goal.length <= 100
//     s and goal consist of lowercase English letters.

 
// Seen this question in a real interview before?
// 1/5



class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};
