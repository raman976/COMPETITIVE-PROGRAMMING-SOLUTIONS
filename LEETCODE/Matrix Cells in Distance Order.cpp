// 1030. Matrix Cells in Distance Order
// Solved
// Easy
// Topics
// premium lock iconCompanies

// You are given four integers row, cols, rCenter, and cCenter. There is a rows x cols matrix and you are on the cell with the coordinates (rCenter, cCenter).

// Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) from the smallest distance to the largest distance. You may return the answer in any order that satisfies this condition.

// The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.

 

// Example 1:

// Input: rows = 1, cols = 2, rCenter = 0, cCenter = 0
// Output: [[0,0],[0,1]]
// Explanation: The distances from (0, 0) to other cells are: [0,1]

// Example 2:

// Input: rows = 2, cols = 2, rCenter = 0, cCenter = 1
// Output: [[0,1],[0,0],[1,1],[1,0]]
// Explanation: The distances from (0, 1) to other cells are: [0,1,1,2]
// The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.

// Example 3:

// Input: rows = 2, cols = 3, rCenter = 1, cCenter = 2
// Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
// Explanation: The distances from (1, 2) to other cells are: [0,1,1,2,2,3]
// There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].

 

// Constraints:

//     1 <= rows, cols <= 100
//     0 <= rCenter < rows
//     0 <= cCenter < cols

 



class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> cells;
        
        // Step 1: Generate all cell coordinates
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cells.push_back({r, c});
            }
        }
        
        // Step 2: Sort by Manhattan distance
        sort(cells.begin(), cells.end(), [&](const vector<int>& a, const vector<int>& b) {
            int da = abs(a[0] - rCenter) + abs(a[1] - cCenter);
            int db = abs(b[0] - rCenter) + abs(b[1] - cCenter);
            return da < db;
        });
        
        // Step 3: Return sorted cells
        return cells;
    }
};
