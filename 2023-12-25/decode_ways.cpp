class Solution {
public:
  int numDecodings(string s) {
    int n = s.length();

    // Handle edge case: if the string is empty, there is no decoding possible.
    if (n == 0) {
      return 0;
    }

    // Create a vector to store the number of ways to decode the string up to
    // the ith index.
    vector<int> dp(n + 1, 0);

    // Base case: there is one way to decode an empty string.
    dp[0] = 1;

    // Loop through the string to calculate the number of ways to decode at each
    // index.
    for (int i = 1; i <= n; ++i) {
      // If the current digit is not '0', add the number of ways to decode the
      // previous index.
      if (s[i - 1] != '0') {
        dp[i] += dp[i - 1];
      }

      // If the current and previous digits form a valid mapping, add the number
      // of ways to decode two indices back.
      if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
        dp[i] += dp[i - 2];
      }
    }

    // The result is stored in the last index of the dp array.
    return dp[n];
  }
};

/*
Time Compleixty: O(n)
Space Complexity: O(n)
*/