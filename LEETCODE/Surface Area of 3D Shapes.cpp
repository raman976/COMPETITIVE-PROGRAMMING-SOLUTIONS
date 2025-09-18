// 892. Surface Area of 3D Shapes
// Easy
// Topics
// premium lock iconCompanies

// You are given an n x n grid where you have placed some 1 x 1 x 1 cubes. Each value v = grid[i][j] represents a tower of v cubes placed on top of cell (i, j).

// After placing these cubes, you have decided to glue any directly adjacent cubes to each other, forming several irregular 3D shapes.

// Return the total surface area of the resulting shapes.

// Note: The bottom face of each shape counts toward its surface area.

 

// Example 1:

// Input: grid = [[1,2],[3,4]]
// Output: 34

// Example 2:

// Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
// Output: 32

// Example 3:

// Input: grid = [[2,2,2],[2,1,2],[2,2,2]]
// Output: 46

 

// Constraints:

//     n == grid.length == grid[i].length
//     1 <= n <= 50
//     0 <= grid[i][j] <= 50



class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int h = grid[i][j];
                if (h > 0) {
                    area += 6 * h;
                    area -= 2 * (h - 1);
                    if (i > 0) area -= 2 * min(h, grid[i - 1][j]); 
                    if (j > 0) area -= 2 * min(h, grid[i][j - 1]); 
                }
            }
        }
        return area;
    }
};
