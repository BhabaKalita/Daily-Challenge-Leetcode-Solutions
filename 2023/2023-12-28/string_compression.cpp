class Solution {
public:
    int dp[101][101];

    // Recursive function to calculate the minimum compressed length
    int dfs(string &s, int left, int K) {
        int k = K;
        // Base case: if remaining characters are less than or equal to k, return 0
        if (s.size() - left <= k) return 0;

        // Memoization: if the result for the current state is already calculated, return it
        if (dp[left][k] >= 0) return dp[left][k];

        int res = k ? dfs(s, left + 1, k - 1) : 10000; // Initialize res with a large value if k is not zero
        int c = 1; // Counter for consecutive identical characters
        for (int i = left + 1; i <= s.size(); ++i) {
            // Update the result considering the compression for the current substring
            res = min(res, dfs(s, i, k) + 1 + (c >= 100 ? 3 : (c >= 10 ? 2 : (c > 1 ? 1 : 0))));

            if (i == s.size()) break;

            // Update the counter for consecutive identical characters
            if (s[i] == s[left]) ++c;
            else if (--k < 0) break;
        }

        // Memoize the result and return it
        return dp[left][K] = res;
    }

    // Main function to get the minimum length of the run-length encoded version
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp)); // Initialize the memoization array with -1
        return dfs(s, 0, k);
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/