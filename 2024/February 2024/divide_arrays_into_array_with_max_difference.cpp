#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to divide an array into groups of three elements
    // such that the difference between the maximum and minimum
    // elements in each group is less than or equal to 'k'.
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int size = nums.size();

        // Check if the size of the array is not divisible by 3.
        if (size % 3 != 0)
            return vector<vector<int>>();  // Return an empty vector if not divisible.

        // Sort the input array in ascending order.
        sort(nums.begin(), nums.end());

        // Initialize the result vector to store groups of three elements.
        vector<vector<int>> result(size / 3, vector<int>(3));
        int groupIndex = 0;

        // Iterate through the array with a step of 3.
        for (int i = 0; i < size; i += 3) {
            // Check if there are three elements in the current group
            // and the difference between the maximum and minimum is <= k.
            if (i + 2 < size && nums[i + 2] - nums[i] <= k) {
                // Assign the current group to the result vector.
                result[groupIndex] = { nums[i], nums[i + 1], nums[i + 2] };
                groupIndex++;
            } else {
                // If the condition is not met, return an empty vector.
                return vector<vector<int>>();
            }
        }

        // Return the resulting vector of groups.
        return result;
    }
};

// Time Complexity:
// The time complexity of this solution is O(n log n), where 'n' is the size of the input array.
// Sorting the array dominates the overall time complexity.

// Space Complexity:
// The space complexity is O(n/3), which simplifies to O(n).
// The space required is mainly for storing the result vector, which contains groups of three elements.