class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length(); // Get the length of the string
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Initialize a 2D DP array with -1 (n x n)
        return Util(0, n - 1, s, dp); // Call the recursive helper function with the full string
    }

    int Util(int i, int j, const string& s, vector<vector<int>>& dp) {
        if (i > j) { // Base case: if the left index exceeds the right, return 0
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j]; // Return the memoized result if already computed

        char firstLetter = s[i]; // Get the first character of the current substring
        int answer = 1 + Util(i + 1, j, s, dp); // Initial answer: 1 (print first character) + result for the remaining string

        for (int k = i + 1; k <= j; k++) { // Loop through the rest of the string
            if (s[k] == firstLetter) { // If a character matches the first character
                // Consider the possibility of printing the substring in two parts
                int betterAnswer = Util(i, k - 1, s, dp) + Util(k + 1, j, s, dp);
                answer = min(answer, betterAnswer); // Choose the minimum number of operations
            }
        }
        return dp[i][j] = answer; // Store the result in the DP array and return it
    }
};
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)