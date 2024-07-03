class Solution {
public:
    int minDifference(vector<int>& nums) {
        // If the size of the array is 4 or less, return 0 because we can change all elements
        if(nums.size() <= 4) {
            return 0;
        }

        // Sort the array
        sort(nums.begin(), nums.end());

        // Initialize the answer with the difference between the largest and smallest elements
        int ans = nums.back() - nums[0];

        // Try removing up to 3 elements from either end and calculate the minimum difference
        for(int i = 0; i <= 3; i++) {
            ans = min(ans, nums[nums.size() - (3 - i) - 1] - nums[i]);
        }

        // Return the minimum difference found
        return ans;
    }
};
// Time Complexity: O(nlogn)
// Space Complexity: O(1)