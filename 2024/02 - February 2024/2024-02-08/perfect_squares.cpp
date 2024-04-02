#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to recursively solve the problem
    int solve(int n, vector<int> &dp) {
        // If n is 0, no squares are needed
        if(!n) return 0;

        // If the solution for n is already calculated, return it
        if(dp[n] != -1) return dp[n];

        // Initialize minimum number of squares needed with n
        int mini = n;

        // Iterate through all possible squares less than or equal to n
        for(int i = 1; i * i <= n; i++) {
            // Recursively calculate the solution for remaining value after taking a square
            mini = min(mini, solve(n - i * i, dp) + 1);
        }

        // Store the solution for n and return it
        return dp[n] = mini;
    }

    // Main function to find the minimum number of perfect squares summing to n
    int numSquares(int n) {
        // Initialize a vector to store previously calculated solutions
        vector<int> dp(n + 1, -1);

        // Call the recursive function to find the solution and return it
        return solve(n, dp);
    }
};

/*
Time Complexity : O(n * sqrt(n))
Space Complexity : O(n)
*/