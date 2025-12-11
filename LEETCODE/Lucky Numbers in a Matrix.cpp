class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;

        for (int i = 0; i < m; i++) {
            // Step 1: find min element in the row
            int minVal = matrix[i][0];
            int colIndex = 0;

            for (int j = 1; j < n; j++) {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    colIndex = j;
                }
            }

            // Step 2: check if this minVal is maximum in its column
            bool isLucky = true;
            for (int k = 0; k < m; k++) {
                if (matrix[k][colIndex] > minVal) {
                    isLucky = false;
                    break;
                }
            }

            if (isLucky) result.push_back(minVal);
        }

        return result;
    }
};
