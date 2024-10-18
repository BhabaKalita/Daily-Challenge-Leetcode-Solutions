class Solution {
public:
    void solve(vector<int>& nums, int index, int curOr, int maxOr, int &count) {
        // If the current OR value equals the maximum OR value, increment the count
        if (curOr == maxOr) {
            count++;
        }

        // Recursively explore all possible subsets starting from the current index
        for (int i = index; i < nums.size(); i++) {
            solve(nums, i + 1, curOr | nums[i], maxOr, count);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        // Find the maximum OR value among all elements in the nums vector
        int maxOr = 0;
        for (auto num : nums) {
            maxOr |= num;
        }

        // Initialize the count to 0
        int count = 0;

        // Start the recursive exploration from index 0 with initial OR value 0
        solve(nums, 0, 0, maxOr, count);

        // Return the final count of subsets with the maximum OR value
        return count;
    }
};

// Time Complexity: O(2^n)
// Space Complexity: O(n)
