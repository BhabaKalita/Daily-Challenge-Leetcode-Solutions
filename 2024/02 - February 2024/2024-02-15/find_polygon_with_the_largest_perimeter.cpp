#include <vector>
#include <algorithm> // for sort

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // Sorting the array in non-decreasing order
        sort(nums.begin(), nums.end());

        long long res = -1, curr = 0; // Initialize result and current perimeter

        // Iterating through the sorted array
        for(int i = 0; i < nums.size(); i++) {
            // Checking if adding the current number makes a valid triangle
            if((curr += nums[i]) > 2 * nums[i])
                res = curr; // Update result if a valid triangle is found
        }
        return res; // Return the largest perimeter found
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/