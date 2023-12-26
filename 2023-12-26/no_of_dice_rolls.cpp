#include <iostream>
#include <vector>

const int MOD = 1000000007;

int numRollsToTarget(int n, int k, int target) {
  // dp[i][j] represents the number of ways to get sum j with i dice
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));

  // Base case: one way to get a sum of 0 with 0 dice
  dp[0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= target; ++j) {
      for (int face = 1; face <= k; ++face) {
        if (j - face >= 0) {
          // Update the number of ways to get the current sum
          dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
        }
      }
    }
  }

  return dp[n][target];
}

/*
    Time Complexity: O(n * target * k)
    Space Complexity: O(n * target)
*/