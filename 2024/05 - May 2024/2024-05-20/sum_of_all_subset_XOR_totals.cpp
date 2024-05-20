class Solution {
public:
    // Function to calculate the sum of XOR of all subsets
    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }

private:
    // Helper function to recursively calculate XOR sum of subsets
    int solve(vector<int>& nums, int index, int currXor) {
        // Base case: if we have processed all elements
        if (index == nums.size()) {
            return currXor;
        }

        // Recur by including the current element in the subset (take)
        int take = solve(nums, index + 1, currXor ^ nums[index]);
        // Recur by not including the current element in the subset (notTake)
        int notTake = solve(nums, index + 1, currXor);

        // Return the sum of both choices
        return take + notTake;
    }
};

/*
Time Complexity: O(2^n)
Space Complexity: O(n)
*/