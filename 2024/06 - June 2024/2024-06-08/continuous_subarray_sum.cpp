class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Map to store remainder of the cumulative sum and its first occurrence index
        unordered_map<int, int> mp;
        int sum = 0;

        // Initialize the map with remainder 0 at index -1
        mp[0] = -1;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];  // Add current element to cumulative sum

            int rem = sum % k;  // Compute the remainder of sum divided by k

            // If remainder has been seen before
            if (mp.find(rem) != mp.end()) {
                // Check if the subarray length is at least 2
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                // Store the index of the first occurrence of this remainder
                mp[rem] = i;
            }
        }

        return false;  // No valid subarray found
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/