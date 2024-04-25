int longestIdealString(string s, int k) {
    int dp[150] = {}; // DP array to store the length of the longest ideal string ending at each character
    int res = 0; // Result variable to store the maximum length of the ideal string found so far

    for (auto& i : s) { // Iterate through each character in the input string
        for (int j = i - k; j <= i + k; ++j) { // Check characters within the range [i-k, i+k]
            dp[i] = max(dp[i], dp[j]); // Update dp[i] with the maximum length found so far
        }
        res = max(res, ++dp[i]); // Update the result with the maximum length found including the current character
    }

    return res; // Return the maximum length of the ideal string
}
/*
Time Complexity: O(n*k)
Space Complexity: O(1)
*/