class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;   // Variable to hold the result sum
        int c = 0;           // Counter to track if there is any case where a < b
        int d = INT_MAX;     // Variable to track the minimum absolute difference, initialized to maximum integer value

        // Iterate over each element in the nums vector
        for (int a : nums) {
            int b = a ^ k;          // Compute b as the result of a XOR k
            res += max(a, b);       // Add the maximum of a and b to the result sum
            c ^= a < b;             // Update c using XOR to toggle based on whether a is less than b
            d = min(d, abs(a - b)); // Update d to be the minimum of its current value and the absolute difference of a and b
        }

        // Adjust the result by subtracting d * c
        // If c is 1, subtract the minimum difference d, otherwise subtract 0
        return res - d * c;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/