class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(3, 0);
        
        // Step 1: Compute sum of each subarray of length k using sliding window
        vector<int> sum(n - k + 1, 0);  // sum[i] stores sum of subarray starting at i
        int windowSum = 0;
        
        // Calculate the sum for the first window (first subarray of length k)
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        sum[0] = windowSum;
        
        // Calculate sum for other subarrays using sliding window
        for (int i = 1; i <= n - k; i++) {
            windowSum += nums[i + k - 1] - nums[i - 1];
            sum[i] = windowSum;
        }
        
        // Step 2: Create leftMax and rightMax arrays
        vector<int> leftMax(n - k + 1, 0), rightMax(n - k + 1, 0);
        
        // leftMax[i] will store the index of the subarray with maximum sum from [0...i]
        leftMax[0] = 0;
        for (int i = 1; i <= n - k; i++) {
            if (sum[i] > sum[leftMax[i - 1]]) {
                leftMax[i] = i;
            } else {
                leftMax[i] = leftMax[i - 1];
            }
        }
        
        // rightMax[i] will store the index of the subarray with maximum sum from [i...n-k]
        rightMax[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; i--) {
            if (sum[i] >= sum[rightMax[i + 1]]) {
                rightMax[i] = i;
            } else {
                rightMax[i] = rightMax[i + 1];
            }
        }
        
        // Step 3: Find the maximum sum by selecting a middle subarray and use leftMax and rightMax to find the best left and right subarrays
        int maxSum = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            int left = leftMax[i - k]; // Best left subarray before i
            int right = rightMax[i + k]; // Best right subarray after i
            int totalSum = sum[left] + sum[i] + sum[right];
            
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {left, i, right};
            }
        }
        
        return result;
    }
};
// Time Complexity:O(n)
// Space Complexity:O(n)
