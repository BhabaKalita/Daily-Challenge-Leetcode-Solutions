#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Initialize an unordered_map to store the cumulative sum frequencies
        unordered_map<int, int> mp({{0, 1}}); // Initialize with {0, 1} to handle cases where pS - goal = 0

        int res = 0; // Initialize result variable to count subarrays with sum equal to the goal
        int pS = 0; // Initialize the partial sum variable

        // Iterate through each element in the input nums
        for (int x : nums) {
            pS += x; // Update partial sum with the current element

            // Increment result by the count of subarrays with sum equal to goal
            res += mp[pS - goal];

            // Increment the count of partial sum in the map
            mp[pS]++;
        }

        return res; // Return the total count of subarrays with sum equal to goal
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/