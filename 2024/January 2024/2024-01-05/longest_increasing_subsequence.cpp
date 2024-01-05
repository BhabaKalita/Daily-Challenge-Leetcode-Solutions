#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive function to find the length of the longest increasing subsequence
    int solve(vector<int>& nums, int n, int curr, int prev, vector<vector<int>> &dp) {
        // If we have processed all elements, return 0
        if(curr == n) return 0;

        // If the result for the current state is already computed, return it
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        // Initialize the length with the result of the subproblem for the next element
        int len = 0 + solve(nums, n, curr+1, prev, dp);

        // If the current element is greater than the previous one, consider it in the subsequence
        if(prev == -1 || nums[curr] > nums[prev])
            len = max(len, 1 + solve(nums, n, curr+1, curr, dp));

        // Save the result in the memoization table and return the length
        return dp[curr][prev+1] = len;
    }

    // Main function to find the length of the longest increasing subsequence
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // Create a memoization table and initialize it with -1
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));

        // Call the recursive function with initial parameters
        return solve(nums, n, 0, -1, dp);
    }
};

// Time Complexity: O(n^2) - Each subproblem is solved once, and there are n^2 subproblems
// Space Complexity: O(n^2) - Memoization table stores results for all subproblems