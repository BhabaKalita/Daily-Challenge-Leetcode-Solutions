#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minDifficulty(vector<int> &A, int D) {
  int n = A.size(), inf = 1e9, maxd;
  // If the number of jobs is less than the number of days, it's not possible to
  // schedule them.
  if (n < D)
    return -1;

  // dp[i] represents the minimum difficulty to schedule jobs starting from i to
  // the end.
  vector<int> dp(n + 1, 1e9);
  dp[n] = 0;

  // Iterate through each day.
  for (int d = 1; d <= D; ++d) {
    // Iterate through each job.
    for (int i = 0; i <= n - d; ++i) {
      maxd = 0;
      dp[i] = inf;

      // Find the maximum difficulty of jobs from i to i + d.
      for (int j = i; j <= n - d; ++j) {
        maxd = max(maxd, A[j]);
        // Update the minimum difficulty for scheduling jobs from i to i + d.
        dp[i] = min(dp[i], maxd + dp[j + 1]);
      }
    }
  }
  // Minimum difficulty to schedule all jobs starting from the first day.
  return dp[0];
}

int main() {
  // Example usage:
  vector<int> jobDifficulty = {6, 5, 4, 3, 2, 1};
  int days = 2;
  int result = minDifficulty(jobDifficulty, days);

  // Print the result
  cout << "Minimum Difficulty: " << result << endl;

  return 0;
}

/*
Time Complexity:O(D * N^2)
Space Complexity:O(N)
*/