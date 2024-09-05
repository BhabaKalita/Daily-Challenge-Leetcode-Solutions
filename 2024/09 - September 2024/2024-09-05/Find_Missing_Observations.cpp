class Solution {
public:
    static vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int m = rolls.size(); // Calculate the size of the given rolls vector
        const int sum_rolls = accumulate(rolls.begin(), rolls.end(), 0); // Calculate the sum of the rolls
        const int total = (n + m) * mean; // Calculate the total sum required to achieve the given mean
        const int miss = total - sum_rolls; // Calculate the missing sum that needs to be distributed among the missing rolls

        // Check if the missing sum is within the possible range (n to 6n)
        if (miss > 6 * n || miss < n) {
            return {}; // If the missing sum is not feasible, return an empty vector
        }

        // Calculate the quotient and remainder of dividing the missing sum by the number of missing rolls
        auto [q, r] = div(miss, n);

        // Create a vector of size n to store the missing rolls
        vector<int> ans(n, q);

        // Fill the first r elements of the vector with q+1 to distribute the remainder evenly
        fill(ans.begin(), ans.begin() + r, q + 1);

        return ans; // Return the vector of missing rolls
    }
};
/*
  Time Complexity: O(m)
  Space Complexity: O(n)
*/
