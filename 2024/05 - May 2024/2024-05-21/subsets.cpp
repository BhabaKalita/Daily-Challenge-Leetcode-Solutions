class Solution {
public:
    vector<vector<int>> res;  // To store all subsets

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;  // Temporary vector to store the current subset
        solve(nums, 0, temp);  // Start the recursive process
        return res;  // Return the result containing all subsets
    }

    void solve(vector<int>& nums, int idx, vector<int>& temp) {
        // Base case: If idx is out of bounds, add the current subset to the result
        if (idx >= nums.size()) {
            res.push_back(temp);
            return;
        }

        // Include the current element in the subset
        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp);
        temp.pop_back();  // Backtrack to explore subsets without the current element

        // Exclude the current element from the subset
        solve(nums, idx + 1, temp);
    }
};

/*
Time Complexity: O(2^n)
Space Complexity: O(n.2^n)
*/