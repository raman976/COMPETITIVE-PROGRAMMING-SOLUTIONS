// 976. Largest Perimeter Triangle
// Solved
// Easy
// Topics
// premium lock iconCompanies

// Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

 

// Example 1:

// Input: nums = [2,1,2]
// Output: 5
// Explanation: You can form a triangle with three side lengths: 1, 2, and 2.

// Example 2:

// Input: nums = [1,2,1,10]
// Output: 0
// Explanation: 
// You cannot use the side lengths 1, 1, and 2 to form a triangle.
// You cannot use the side lengths 1, 1, and 10 to form a triangle.
// You cannot use the side lengths 1, 2, and 10 to form a triangle.
// As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.

 

// Constraints:

//     3 <= nums.length <= 104
//     1 <= nums[i] <= 106

 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 4,02,131/653.5K
// Acceptance Rate
// 61.5%




class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend()); // Sort in descending order
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i+1] + nums[i+2] > nums[i]) {
                // Triangle can be formed
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        
        return 0; // No triangle possible
    }
};
