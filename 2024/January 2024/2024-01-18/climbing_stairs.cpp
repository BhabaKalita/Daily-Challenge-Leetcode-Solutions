#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        // Create a vector to store intermediate results
        // dp[i] represents the number of distinct ways to climb to step i
        // Initialize the vector with zeros
        vector<int> dp(n + 1, 0);

        // Base case: there is 1 way to climb 0 or 1 step
        if (n <= 1) {
            return 1;
        }

        // Base cases for 1 and 2 steps
        dp[1] = 1;
        dp[2] = 2;

        // Iterate from step 3 to n, filling in dp array
        for (int i = 3; i <= n; i++) {
            // The number of ways to reach step i is the sum of ways to reach steps i-1 and i-2
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // The final result is the number of distinct ways to climb to the top (step n)
        return dp[n];
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/