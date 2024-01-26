#include <vector>

class Solution {
public:
    int findPaths(int m, int n, int N, int x, int y) {
        const int M = 1000000000 + 7;

        // Create a 2D vector to store the dynamic programming table
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the starting point with 1 (the ball is at position (x, y))
        dp[x][y] = 1;

        int count = 0;

        // Iterate through each move from 1 to N
        for (int moves = 1; moves <= N; moves++) {
            // Create a temporary 2D vector to store the updated dynamic programming table
            vector<vector<int>> temp(m, vector<int>(n, 0));

            // Iterate through each cell in the grid
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    // If the ball is at the boundary, increment the count with the current cell's value
                    if (i == m - 1) count = (count + dp[i][j]) % M;
                    if (j == n - 1) count = (count + dp[i][j]) % M;
                    if (i == 0) count = (count + dp[i][j]) % M;
                    if (j == 0) count = (count + dp[i][j]) % M;

                    // Calculate the number of ways to reach the current cell in the next move
                    temp[i][j] = (
                        ((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % M +
                        ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % M
                    ) % M;
                }
            }

            // Update the dynamic programming table with the temporary table
            dp = temp;
        }

        // Return the total number of paths that the ball can take to go out of the grid
        return count;
    }
};

// Time Complexity: O(N * m * n), where N is the number of moves, and m and n are the dimensions of the grid.
// Space Complexity: O(m * n), as we use a 2D vector to store the dynamic programming table.
