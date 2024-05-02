class Solution {
public:
    /**
     * Finds the maximum value K such that nums[i] + nums[j] = 0.
     * Assumes that the input vector `nums` is sorted in ascending order.
     *
     * @param nums A vector of integers.
     * @return The maximum value K such that nums[i] + nums[j] = 0.
     */
    int findMaxK(vector<int>& nums) {
        // Sort the input vector in ascending order
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.size() - 1;
        int res = -1;

        // Two-pointer approach to find the pair whose sum is 0
        while (low < high) {
            if (nums[low] + nums[high] == 0)
                return res = nums[high];

            if (nums[low] + nums[high] < 0)
                low++;
            else
                high--;
        }

        return res;
    }
};
/*
Time Complexity: O(n log n)
Space Complexity: O(1)
*/