#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1; // Initialize the maximum size of the subset
        int num = -1; // Initialize the last number added to the subset
        vector<int> v; // Initialize the result vector

        // Sort the input array
        sort(nums.begin(), nums.end());

        // Dynamic programming approach to find the largest divisible subset
        vector<int> dp(n, 1); // Initialize a DP array with all elements set to 1
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (!(nums[i] % nums[j]) && dp[i] < dp[j] + 1) {
                    // If nums[i] is divisible by nums[j] and adding nums[i] to the subset
                    // increases its size, update dp[i]
                    dp[i] = dp[j] + 1;
                    if (maxi < dp[i]) {
                        maxi = dp[i]; // Update the maximum subset size
                    }
                }
            }
        }

        // Reconstruct the largest divisible subset
        for (int i = n - 1; i >= 0; i--) {
            if (maxi == dp[i] && (num == -1 || !(num % nums[i]))) {
                // If dp[i] equals the maximum subset size and nums[i] can be added to the subset
                v.push_back(nums[i]); // Add nums[i] to the subset
                maxi--; // Decrement the subset size
                num = nums[i]; // Update the last number added to the subset
            }
        }

        return v; // Return the largest divisible subset
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/