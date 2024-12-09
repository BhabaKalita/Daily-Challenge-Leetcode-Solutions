class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans; // Stores the results of each query as a boolean.

        // Precompute a `converted` array where consecutive numbers with the same parity
        // (even/odd) are grouped together.
        vector<int> converted(1, 0); // Start with a dummy value (0) for convenience.

        // Build the `converted` array.
        for (int i = 1, j = 0; i < nums.size(); i++) {
            // If current number has the same parity as the previous one, increment `j`.
            if ((nums[i] % 2) == (nums[i - 1] % 2)) j++;
            // Append the value of `j` to `converted`.
            converted.push_back(j);
        }

        // Process each query in the `queries` vector.
        for (auto q : queries) {
            // Check if the start and end indices of the query belong to the same group (same parity).
            ans.push_back(converted[q[0]] == converted[q[1]]);
        }

        return ans; // Return the results of all queries.
    }
};
// Time Complexity: O(n+m), where nn is the size of nums and mm is the number of queries.
// Space Complexity: O(n+m) due to the converted array and the ans vector.
