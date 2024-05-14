class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();      // number of rows
        int n = grid[0].size();   // number of columns
        int maxGold = 0;          // variable to keep track of maximum gold collected

        // Iterate through each cell in the grid
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                // Call the helper function findMaxGold starting from each cell
                maxGold = max(maxGold, findMaxGold(grid, m, n, r, c));
            }
        }
        return maxGold;           // return the maximum gold collected
    }

    // Direction vectors for moving up, right, down, and left
    int DIR[5] = {0, 1, 0, -1, 0};

    int findMaxGold(vector<vector<int>>& grid, int m, int n, int r, int c) {
        // Check for out-of-bounds and if the cell contains 0 (no gold)
        if (r < 0 || r == m || c < 0 || c == n || grid[r][c] == 0) return 0;

        // Store the current cell's gold amount
        int origin = grid[r][c];
        // Mark the cell as visited by setting it to 0
        grid[r][c] = 0;
        int maxGold = 0;

        // Explore all four possible directions
        for (int i = 0; i < 4; i++) {
            maxGold = max(maxGold, findMaxGold(grid, m, n, r + DIR[i], c + DIR[i + 1]));
        }

        // Backtrack: restore the cell's original gold amount
        grid[r][c] = origin;

        // Return the maximum gold collected from this path plus the current cell's gold
        return maxGold + origin;
    }
};

/*
Time Complexity: O(M * N * 4^K)
Space Complexity: O(M * N)
*/