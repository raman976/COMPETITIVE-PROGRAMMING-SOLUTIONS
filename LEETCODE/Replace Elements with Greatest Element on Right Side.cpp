// 1299. Replace Elements with Greatest Element on Right Side
// Solved
// Easy
// Topics
// premium lock iconCompanies
// Hint

// Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

// After doing so, return the array.

 

// Example 1:

// Input: arr = [17,18,5,4,6,1]
// Output: [18,6,6,6,1,-1]
// Explanation: 
// - index 0 --> the greatest element to the right of index 0 is index 1 (18).
// - index 1 --> the greatest element to the right of index 1 is index 4 (6).
// - index 2 --> the greatest element to the right of index 2 is index 4 (6).
// - index 3 --> the greatest element to the right of index 3 is index 4 (6).
// - index 4 --> the greatest element to the right of index 4 is index 5 (1).
// - index 5 --> there are no elements to the right of index 5, so we put -1.

// Example 2:

// Input: arr = [400]
// Output: [-1]
// Explanation: There are no elements to the right of index 0.

 

// Constraints:

//     1 <= arr.length <= 104
//     1 <= arr[i] <= 105

 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 4,98,427/695.3K
// Acceptance Rate
// 71.7%







class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxRight = -1;  // last element always becomes -1

        // Traverse from the end
        for (int i = n - 1; i >= 0; --i) {
            int temp = arr[i];   // store current value
            arr[i] = maxRight;   // replace with current max on right
            maxRight = max(maxRight, temp); // update maxRight
        }

        return arr;
    }
};
