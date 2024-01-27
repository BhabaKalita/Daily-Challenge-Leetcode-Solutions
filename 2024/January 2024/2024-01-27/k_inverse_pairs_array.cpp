#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        // Initialize a 2D array to store the dynamic programming results
        // dp[i][j] represents the number of permutations with i elements and j inverse pairs
        int dp[1001][1001] = {1};

        // Iterate through each element count i
        for (int i = 1; i <= n; i++) {
            // Iterate through each possible number of inverse pairs j
            for (int j = 0; j <= k; j++) {
                // Iterate through each possible number x of elements from the previous row that contribute to the current inverse pairs count
                for (int x = 0; x <= min(j, i - 1); x++) {
                    // Update the dp table by adding the count of permutations from the previous row
                    if (j - x >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % 1000000007;
                    }
                }
            }
        }

        // Return the result for n elements and k inverse pairs
        return dp[n][k];
    }
};

/*
Time Complexity: O(n * k^2)
Space Complexity: O(n * k)
*/