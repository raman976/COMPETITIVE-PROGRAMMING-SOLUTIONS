// 1200. Minimum Absolute Difference
// Solved
// Easy
// Topics
// premium lock iconCompanies
// Hint

// Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

//     a, b are from arr
//     a < b
//     b - a equals to the minimum absolute difference of any two elements in arr

 

// Example 1:

// Input: arr = [4,2,1,3]
// Output: [[1,2],[2,3],[3,4]]
// Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.

// Example 2:

// Input: arr = [1,3,6,10,15]
// Output: [[1,3]]

// Example 3:

// Input: arr = [3,8,-10,23,19,-4,-14,27]
// Output: [[-14,-10],[19,23],[23,27]]

 

// Constraints:

//     2 <= arr.length <= 105
//     -106 <= arr[i] <= 106

 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 2,69,064/378.7K
// Acceptance Rate
// 71.0%



class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int minDiff = INT_MAX;
        // First pass: find the minimum absolute difference
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, arr[i] - arr[i-1]);
        }
        
        vector<vector<int>> result;
        // Second pass: collect all pairs with the minimum difference
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i-1] == minDiff) {
                result.push_back({arr[i-1], arr[i]});
            }
        }
        
        return result;
    }
};
