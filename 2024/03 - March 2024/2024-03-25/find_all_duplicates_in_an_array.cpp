class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Check if the input array is empty
        if(nums.empty())
            return {};

        // Vector to store the duplicate elements
        vector<int> ans;

        // Iterate through the array
        for(int i = 0; i < nums.size(); i++) {
            // If the number at the current index is negative,
            // it means it's a duplicate and we add its absolute value to ans
            if(nums[abs(nums[i]) - 1] < 0)
                ans.push_back(abs(nums[i]));

            // Negate the value at the index corresponding to the current number
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }

        return ans; // Return the list of duplicates
    }
};

/*
Time Complexity: O(n) where n is the number of elements in the input array.
Space Complexity: O(1)
*/