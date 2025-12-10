// 1394. Find Lucky Integer in an Array
// Solved
// Easy
// Topics
// premium lock iconCompanies
// Hint

// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

// Return the largest lucky integer in the array. If there is no lucky integer return -1.

 

// Example 1:

// Input: arr = [2,2,3,4]
// Output: 2
// Explanation: The only lucky number in the array is 2 because frequency[2] == 2.

// Example 2:

// Input: arr = [1,2,2,3,3,3]
// Output: 3
// Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

// Example 3:

// Input: arr = [2,2,2,3,3]
// Output: -1
// Explanation: There are no lucky numbers in the array.

 

// Constraints:

//     1 <= arr.length <= 500
//     1 <= arr[i] <= 500

 
// Seen this question in a real interview before?
// 1/5



class Solution {
public:
    int findLucky(vector<int>& arr) {
        // Frequency array since arr[i] <= 500
        int freq[501] = {0};

        for (int num : arr) {
            freq[num]++;
        }

        int result = -1;
        // Check each number to see if it's lucky
        for (int i = 1; i <= 500; ++i) {
            if (freq[i] == i) {
                result = i; // keep largest
            }
        }

        return result;
    }
};
