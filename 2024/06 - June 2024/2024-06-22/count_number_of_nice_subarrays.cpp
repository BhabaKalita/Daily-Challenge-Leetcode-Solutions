class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();  // Get the size of the input array
        vector<int> cnt(n + 1, 0);  // Create a count array to store the frequency of prefix sums
        cnt[0] = 1;  // Initialize the count for prefix sum 0 to 1 (to handle cases where the subarray starts from the beginning)
        int ans = 0, t = 0;  // Initialize the result (ans) and the prefix sum of odd numbers (t)

        // Iterate through each element in the array
        for (int v : nums) {
            t += v & 1;  // Increment t if the current element is odd (v & 1 is 1 if v is odd, 0 if even)

            // If the difference between current prefix sum and k exists in cnt array, it means we found a valid subarray
            if (t - k >= 0) {
                ans += cnt[t - k];
            }

            // Increment the count of the current prefix sum
            cnt[t]++;
        }

        return ans;  // Return the total count of valid subarrays
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/