class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0;  // To keep track of the number of patches added
        int i = 0;      // Pointer to iterate through the nums array
        long miss = 1;  // The smallest number that can't be formed using the array and patches

        // Continue until we can form all numbers up to n
        while (miss <= n) {
            // If the current number in nums is less than or equal to miss, use it
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];  // Add nums[i] to miss, extending the range we can achieve
                i++;              // Move to the next number in nums
            } else {
                // If nums[i] is greater than miss, add miss as a patch
                miss += miss;     // Double the miss to include the patch
                count++;          // Increment the number of patches added
            }
        }

        // Return the number of patches added
        return count;
    }
};

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/