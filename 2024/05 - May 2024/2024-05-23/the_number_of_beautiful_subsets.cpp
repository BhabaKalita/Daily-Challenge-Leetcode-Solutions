class Solution {
public:
    int v[1001];  // Array to keep track of the frequency of elements in the current subset

    // Helper function to recursively count the number of beautiful subsets
    int solve(int idx, vector<int>& nums, int k) {
        // If all elements have been considered, count the current subset as valid
        if (idx == nums.size())
            return 1;

        int take = 0;
        // Check if the current element can be added to the subset without violating the condition
        if (nums[idx] - k < 0 || v[nums[idx] - k] == 0) {
            v[nums[idx]]++;           // Include the current element in the subset
            take = solve(idx + 1, nums, k);  // Recursively consider the next element
            v[nums[idx]]--;           // Backtrack and remove the current element from the subset
        }

        // Count the number of subsets that do not include the current element
        int notTake = solve(idx + 1, nums, k);

        // Return the total number of valid subsets
        return take + notTake;
    }

    // Main function to find the number of beautiful subsets
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // Sort the input array
        memset(v, 0, sizeof(v));         // Initialize the frequency array to zero
        return solve(0, nums, k) - 1;    // Call the helper function and subtract 1 to exclude the empty subset
    }
};
/*
Time Complexity: O(2^n)
Space Complexity: O(n)
*/