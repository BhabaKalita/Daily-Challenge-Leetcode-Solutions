#include <vector>
#include <climits> // for INT_MAX
using namespace std;

class Solution {
public:
    // Helper function for dynamic programming
    int solve(vector<vector<int>>& m, int r, int c, vector<vector<int>> &dp) {
        // Base case: if we are at the last row, return the value in the matrix
        if (r == m.size() - 1 && c < m.size() && c >= 0)
            return m[r][c];

        // Base case: if the column index is out of bounds, return INT_MAX
        if (c >= m[0].size() or c < 0)
            return INT_MAX;

        // If the value is already calculated, return it
        if (dp[r][c] != INT_MAX)
            return dp[r][c];

        // Recursive case: calculate the minimum falling path sum
        dp[r][c] = m[r][c] + min(min(solve(m, r + 1, c - 1, dp), solve(m, r + 1, c, dp)), solve(m, r + 1, c + 1, dp));

        return dp[r][c];
    }

    // Main function to find the minimum falling path sum
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX)); // DP table

        int ans = INT_MAX; // Initialize answer to maximum possible value
        // Iterate through each column in the first row to find the minimum falling path sum
        for (int c = 0; c < col; c++) {
            ans = min(ans, solve(matrix, 0, c, dp));
        }
        return ans; // Return the minimum falling path sum
    }
};

// Time Complexity: O(row * col) - Each cell in the matrix is visited once
// Space Complexity: O(row * col) - Additional space is used for the DP table
