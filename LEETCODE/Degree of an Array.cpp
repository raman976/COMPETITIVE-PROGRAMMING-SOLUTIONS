// 697. Degree of an Array
// Easy
// Topics
// premium lock iconCompanies
// Hint

// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

 

// Example 1:

// Input: nums = [1,2,2,3,1]
// Output: 2
// Explanation: 
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.

// Example 2:

// Input: nums = [1,2,2,3,1,4,2]
// Output: 6
// Explanation: 
// The degree is 3 because the element 2 is repeated 3 times.
// So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.

 

// Constraints:

//     nums.length will be between 1 and 50,000.
//     nums[i] will be an integer between 0 and 49,999.

 



#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        unordered_map<int, int> lastIndex;
        unordered_map<int, int> count;

        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (firstIndex.find(num) == firstIndex.end()) {
                firstIndex[num] = i;  // store first occurrence
            }
            lastIndex[num] = i;       // update last occurrence
            count[num]++;             // update frequency
        }

        int degree = 0;
        for (auto& it : count) {
            degree = max(degree, it.second); // find the degree
        }

        int minLength = n; // initialize with max possible length
        for (auto& it : count) {
            if (it.second == degree) {
                int num = it.first;
                int length = lastIndex[num] - firstIndex[num] + 1;
                minLength = min(minLength, length);
            }
        }

        return minLength;
    }
};
