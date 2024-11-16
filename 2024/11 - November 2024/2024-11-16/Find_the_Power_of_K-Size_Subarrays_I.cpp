class Solution {
public:
    // Function to find the end elements of each sliding window of length `k` in `nums`
    // If the window contains exactly `k` consecutive elements, append the end element;
    // otherwise, append -1
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;   // Result vector to store the end elements or -1
        int n = nums.size(); // Get the size of the input vector `nums`

        int l = 0;         // Left boundary of the sliding window
        int consec = 1;    // Count of consecutive elements in the current window

        // Expand the window by moving the right pointer `r`
        for (int r = 0; r < n; r++) {

            // If the current element and the previous element are consecutive, increment `consec`
            if (r > 0 && nums[r - 1] + 1 == nums[r])
                consec++;

            // Shrink the window from the left if its size exceeds `k`
            if (r - l + 1 > k) {
                // If the left element and its next element are consecutive, decrement `consec`
                if (nums[l] + 1 == nums[l + 1])
                    consec--;
                l++; // Move the left boundary of the window right
            }

            // Check if the window size is exactly `k`
            if (r - l + 1 == k)
                // If all `k` elements in the window are consecutive, add `nums[r]` to the result
                // Otherwise, add -1
                res.push_back(consec == k ? nums[r] : -1);
        }

        return res;  // Return the result vector
    }
};
// Time complexity = O(n)
// Space Complexity = O(n)
