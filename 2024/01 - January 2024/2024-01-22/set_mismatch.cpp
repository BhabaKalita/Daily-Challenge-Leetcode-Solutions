#include <vector>

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        // Initialize a vector to count occurrences of each number (from 1 to n)
        vector<int> count(n + 1, 0);

        // Iterate through the nums vector to count occurrences
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
        }

        // Variables to store the duplicate and missing values
        int dup = -1, miss = -1;

        // Iterate through the count vector to find the duplicate and missing values
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2)
                dup = i;  // Duplicate value
            else if (count[i] == 0)
                miss = i;  // Missing value
        }

        // Return the result as a vector {duplicate, missing}
        return {dup, miss};
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/