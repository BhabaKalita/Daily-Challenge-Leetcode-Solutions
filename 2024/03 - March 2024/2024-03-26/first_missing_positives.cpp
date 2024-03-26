class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // Swap A[i] with A[A[i] - 1] to put A[i] to its correct position
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first positive integer that does not match its index
        for(int i = 0; i < n; ++i) {
            if(nums[i] != i + 1) {
                return i + 1; // Return the smallest missing positive integer
            }
        }

        // If all integers from 1 to n are present, return n + 1
        return n + 1;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
