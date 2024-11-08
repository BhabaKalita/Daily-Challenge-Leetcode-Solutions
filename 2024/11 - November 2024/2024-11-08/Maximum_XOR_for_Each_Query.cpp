class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int n = nums.size();               // Get the size of the input array `nums`
        vector<int> res(n);                // Initialize a result vector of size `n`
        int XOR = 0;                       // Initialize a variable `XOR` to store cumulative XOR of elements in `nums`

        // Step 1: Calculate cumulative XOR of all elements in `nums`
        for(int i = 0; i < n; i++) {
            XOR ^= nums[i];                // XOR each element in `nums` with `XOR`
        }

        // Step 2: Create a mask with `maximumBit` bits set to 1
        int mask = (1 << maximumBit) - 1;  // `1 << maximumBit` shifts 1 to the left by `maximumBit` positions,
                                           // then subtracting 1 makes the `maximumBit` bits all "1"s (e.g., 111... for `maximumBit` length)

        // Step 3: Populate `res` by finding maximum XOR with the mask for each prefix of `nums`
        for(int i = 0; i < n; i++) {
            int k = XOR ^ mask;            // XOR cumulative `XOR` with `mask` to get the maximum XOR value with the bits set
            res[i] = k;                    // Store the result in `res`

            XOR ^= nums[n - 1 - i];        // Remove the effect of `nums[n-1-i]` from `XOR` for the next iteration
                                           // (this progressively excludes elements from the cumulative XOR)
        }

        return res;                        // Return the result vector
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(n)
*/
