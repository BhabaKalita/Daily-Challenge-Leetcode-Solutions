#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        // Calculate the size of the vector
        int n = nums.size();

        // Calculate the sum of numbers from 0 to n
        int res = n * (n + 1) / 2;

        // Calculate the total sum of numbers in the vector
        int tot = 0;
        for (int i = 0; i < n; i++)
            tot += nums[i];

        // Return the difference between the sum of numbers from 0 to n and the total sum of numbers in the vector
        return res - tot;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/