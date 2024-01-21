#include <vector>
using namespace std;

class Solution {
public:
    // Function to calculate the maximum amount that can be robbed
    int rob(vector<int>& nums) {
        int n = nums.size();

        // If there is only one house, return its value
        if (n == 1)
            return nums[0];

        // Create a dynamic programming array to store maximum amount at each house
        vector<int> dp(n, 0);

        // Initialize base cases for the first two houses
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Iterate through the rest of the houses
        for (int i = 2; i < n; i++) {
            // Calculate the maximum amount that can be robbed at the current house
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        // Return the maximum amount that can be robbed from all houses
        return dp[n - 1];
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/