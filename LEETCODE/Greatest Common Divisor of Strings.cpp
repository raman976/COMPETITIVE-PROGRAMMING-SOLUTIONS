// 1071. Greatest Common Divisor of Strings
// Solved
// Easy
// Topics
// premium lock iconCompanies
// Hint

// For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

// Example 1:

// Input: str1 = "ABCABC", str2 = "ABC"

// Output: "ABC"

// Example 2:

// Input: str1 = "ABABAB", str2 = "ABAB"

// Output: "AB"

// Example 3:

// Input: str1 = "LEET", str2 = "CODE"

// Output: ""

// Example 4:

// Input: str1 = "AAAAAB", str2 = "AAA"

// Output: ""​​​​​​​

 

// Constraints:

//     1 <= str1.length, str2.length <= 1000
//     str1 and str2 consist of English uppercase letters.

 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 8,85,391/1.7M
// Acceptance Rate
// 53.0%


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If they don't match the concatenation property, no gcd string exists
        if (str1 + str2 != str2 + str1) return "";
        
        // Compute GCD of lengths
        int g = std::gcd(str1.size(), str2.size());
        
        // Return the first 'g' characters of str1
        return str1.substr(0, g);
    }
};
