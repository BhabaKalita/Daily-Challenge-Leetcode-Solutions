class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOps) {
        // Define the search space: 
        // 'low' represents the smallest possible size of the largest bag (minimum 1),
        // 'high' is the maximum value in the array (the worst-case largest bag size).
        int low = 1, high = *max_element(nums.begin(), nums.end());

        // Perform binary search to find the optimal maximum bag size.
        while (low < high) {
            // Calculate the middle value of the current range.
            int mid = low + (high - low) / 2;

            // Variable to count the number of operations required for the current 'mid'.
            int ops = 0;

            // Iterate through each bag size in 'nums'.
            for (int n : nums) {
                // Calculate the number of operations needed to reduce bag 'n' to size 'mid' or smaller.
                // (n - 1) / mid ensures that we correctly calculate the number of splits.
                ops += (n - 1) / mid;

                // Early exit: if the required operations exceed 'maxOps', we can stop checking.
                if (ops > maxOps) break;
            }

            // If the number of operations is within the allowed limit, try a smaller bag size.
            if (ops <= maxOps) {
                high = mid;
            } 
            // Otherwise, try a larger bag size.
            else {
                low = mid + 1;
            }
        }

        // The binary search ends when 'low' equals 'high', which is the minimum size of the largest bag.
        return high;
    }
};
// Complexity: Time O(N * log M) & Space O(1)
