class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long totalSum = 0;
        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Find the remainder when the total sum is divided by p
        int rem = totalSum % p;
        // If the remainder is 0, the total sum is already divisible by p
        if (rem == 0) return 0;

        // A hashmap to store (prefix sum mod p) -> index
        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1;  // Initialize to handle the case of the full prefix sum
        long prefixSum = 0;  // Variable to store the running prefix sum
        int minLength = nums.size();  // Initialize the minimum length of the subarray

        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];  // Add the current number to the prefix sum
            int currentMod = prefixSum % p;  // Find the current prefix sum mod p
            int targetMod = (currentMod - rem + p) % p;  // The mod we are looking for to adjust the remainder

            // Check if we've seen this target remainder in a previous prefix sum
            if (prefixMod.find(targetMod) != prefixMod.end()) {
                // Update the minimum length of the subarray that can be removed
                minLength = min(minLength, i - prefixMod[targetMod]);
            }

            // Store the current prefix sum mod p with its index
            prefixMod[currentMod] = i;
        }

        // If minLength is still the size of the array, it means we couldn't find a valid subarray, return -1
        return minLength == nums.size() ? -1 : minLength;
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(n)
*/
