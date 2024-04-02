#include <vector>
#include <cstring> // For memset

using namespace std;

class Solution {
public:
    // DP array to memoize results
    int dp[70][70][70] = {};

    // Function to calculate the maximum cherries picked
    int cherryPickup(vector<vector<int>>& grid) {
        // Initializing DP array with -1
        memset(dp, -1, sizeof(dp));

        // Getting dimensions of the grid
        int m = grid.size(), n = grid[0].size();

        // Starting DFS from top row, columns 0 and n - 1
        return dfs(grid, m, n, 0, 0, n - 1);
    }

    // Depth-first search function with memoization
    int dfs(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2) {
        // If reached to bottom row, return 0
        if (r == m) return 0;

        // If result is already calculated, return it
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        // Initializing maximum cherries picked for this state
        int ans = 0;

        // Loop through possible moves for both people
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Calculate new column positions
                int nc1 = c1 + i, nc2 = c2 + j;

                // Check if new column positions are within bounds
                if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                    // Recursively call DFS for the next row
                    ans = max(ans, dfs(grid, m, n, r + 1, nc1, nc2));
                }
            }
        }

        // Calculate cherries picked in this step
        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];

        // Memoize the result and return it
        return dp[r][c1][c2] = ans + cherries;
    }
};

