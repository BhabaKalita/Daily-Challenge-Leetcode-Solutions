class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();            // Get the size of the input array
        int flipped = 0;                // A variable to track the cumulative effect of flips
        int res = 0;                    // The result to count the number of flips performed
        vector<int> isFlipped(n, 0);    // An auxiliary array to mark the positions where flips occur

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                // If we have passed at least k elements, we need to remove the effect of the flip
                // that happened k positions ago from the flipped variable
                flipped ^= isFlipped[i - k];
            }

            // If the current bit is the same as the cumulative effect of flips, it means we need to flip
            if (flipped == nums[i]) {
                // If flipping at this position will go beyond the array length, it's not possible
                if (i + k > n) {
                    return -1;
                }

                // Mark this position as flipped
                isFlipped[i] = 1;
                // Update the cumulative effect of flips
                flipped ^= 1;
                // Increment the result as we performed a flip
                res++;
            }
        }

        return res;  // Return the total number of flips performed
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)