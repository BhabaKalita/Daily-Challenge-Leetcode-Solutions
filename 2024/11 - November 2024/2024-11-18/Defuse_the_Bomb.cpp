class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();             // Get the size of the code array
        vector<int> ans(n, 0);            // Initialize a result array of size `n` filled with 0s

        if (k == 0) return ans;           // If k is 0, the decrypted code is simply an array of 0s

        // Case when k > 0: We are summing up the next k elements
        if (k > 0) {
            int wsum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);  // Calculate the sum of the first `k` elements (starting from index 1)
            ans[0] = wsum;                // Assign this sum to the first element of `ans`

            // Use a sliding window to calculate sums for each position in `ans`
            for (int l = 1, r = k + 1; l < n; r++, l++) {
                wsum += -code[l] + code[r % n];  // Adjust the window sum by removing `code[l]` and adding `code[r % n]`
                ans[l] = wsum;                   // Store the calculated sum in the answer array
            }
            return ans;                          // Return the result when k > 0
        }

        // Case when k < 0: We are summing up the previous -k elements
        k = -k;                                  // Convert k to positive for easier indexing
        int wsum = accumulate(code.end() - k, code.end(), 0);  // Calculate the sum of the last `k` elements
        ans[0] = wsum;                            // Assign this sum to the first element of `ans`

        // Use a sliding window to calculate sums for each position in `ans`
        for (int r = 0, l = n - k; r < n - 1; r++, l++) {
            wsum += -code[l % n] + code[r];       // Adjust the window sum by removing `code[l % n]` and adding `code[r]`
            ans[r + 1] = wsum;                    // Store the calculated sum in the answer array
        }
        return ans;                               // Return the result when k < 0
    }
};
// Time Complexity  :O(n)
// Space Complexity : O(n)
