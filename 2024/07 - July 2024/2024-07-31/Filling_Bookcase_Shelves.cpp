class Solution {
public:
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {
        int n = books.size();
        // dp[i] represents the minimum height to place the first i books on the shelf
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;  // Base case: no books require 0 height

        for (int i = 1; i <= n; ++i) {
            int total_width = 0;
            int max_height = 0;
            for (int j = i; j > 0; --j) {
                total_width += books[j-1][0];
                if (total_width > shelfWidth) {
                    break;  // Stop if adding another book exceeds the shelf width
                }
                max_height = std::max(max_height, books[j-1][1]);
                // Update dp[i] with the minimum height by placing books[j-1] to books[i-1] on the same shelf
                dp[i] = std::min(dp[i], dp[j-1] + max_height);
            }
        }

        return dp[n];  // Return the minimum height to place all books
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)