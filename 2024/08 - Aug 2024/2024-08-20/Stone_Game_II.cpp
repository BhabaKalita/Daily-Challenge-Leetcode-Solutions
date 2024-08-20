class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();  // Get the number of piles

        // Create a 2D DP array where dp[i][m] represents the maximum number of stones
        // the current player can get starting from index i with M = m
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Create a suffix sum array where suffixSum[i] represents the sum of all piles
        // from index i to the end of the array
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];  // Initialize the last element

        // Fill the suffix sum array in reverse order
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // Populate the DP table in reverse order
        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                // If we can take all remaining piles starting from index i
                if (i + 2 * m >= n) {
                    dp[i][m] = suffixSum[i];  // Take all remaining stones
                } else {
                    // Try taking x piles, where x ranges from 1 to 2 * M
                    for (int x = 1; x <= 2 * m; x++) {
                        // Maximize the stones the current player can get by choosing the best move
                        dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m, x)]);
                    }
                }
            }
        }

        // The answer is the maximum number of stones the first player can get starting from index 0 with M = 1
        return dp[0][1];
    }
};
// // Time Complexity: O(n^3)
// // Space Complexity: O(n^2)