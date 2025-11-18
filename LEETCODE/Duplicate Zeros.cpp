// 1089. Duplicate Zeros
// Solved
// Easy
// Topics
// premium lock iconCompanies
// Hint

// Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

// Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

 

// Example 1:

// Input: arr = [1,0,2,3,0,4,5,0]
// Output: [1,0,0,2,3,0,0,4]
// Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

// Example 2:

// Input: arr = [1,2,3]
// Output: [1,2,3]
// Explanation: After calling your function, the input array is modified to: [1,2,3]

 

// Constraints:

//     1 <= arr.length <= 104
//     0 <= arr[i] <= 9

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        // Step 1: Count zeros to be duplicated
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) zeros++;
        }

        int i = n - 1;          // original pointer
        int j = n + zeros - 1;  // final pointer (virtual extended array)

        // Step 2: Work backwards and fill the array
        while (i < j) {
            if (j < n) arr[j] = arr[i];

            if (arr[i] == 0) {
                j--;
                if (j < n) arr[j] = 0;   // duplicate zero
            }

            i--;
            j--;
        }
    }
};
