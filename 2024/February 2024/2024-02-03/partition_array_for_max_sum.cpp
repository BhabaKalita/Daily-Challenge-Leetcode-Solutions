#include <vector>
#include <algorithm>
#include <cstring>  // for memset

class Solution {
public:
    int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
        int N = arr.size();
        int K = k + 1;

        // Dynamic programming array to store the maximum sum for each subarray
        int dp[k + 1];
        std::memset(dp, 0, sizeof(dp));

        // Iterate through the array in reverse order
        for (int start = N - 1; start >= 0; start--) {
            int currMax = 0;
            int end = std::min(N, start + k);

            // Iterate within the current subarray to find the maximum element
            for (int i = start; i < end; i++) {
                currMax = std::max(currMax, arr[i]);
                // Update the dp array with the maximum sum for the current subarray
                dp[start % K] = std::max(dp[start % K], dp[(i + 1) % K] + currMax * (i - start + 1));
            }
        }
        // The maximum sum for the entire array is stored at index 0 in the dp array
        return dp[0];
    }
};

/*
Time Complexity: O(N * k)
Space Complexity: O(k)
*/