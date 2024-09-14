class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(); // Calculate the size of the given nums vector
        int m = max_element(nums.begin(), nums.end()) - nums.begin(); // Find the index of the maximum element

        int maxLen = 0, x = nums[m]; // Initialize the maximum length and the maximum element value

        for (int i = m; i < n; i++) {
            int len = 0; // Initialize the current length

            while (i < n && nums[i] == x) {
                i++; // Increment the index
                len++; // Increment the length
            }

            maxLen = max(maxLen, len); // Update the maximum length if necessary
        }

        return maxLen; // Return the maximum length
    }
};
/*
  Time Complexity : O(n^2)
  Space Complexity : O(1)
*/
