#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to calculate the maximum sum of happiness
    // Parameters:
    //   happiness: a vector of integers representing happiness values
    //   k: an integer representing the number of happiness values to consider
    // Returns:
    //   the maximum sum of happiness
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Synchronize the C++ standard streams with the C standard streams
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        // Sort the happiness values in non-increasing order
        sort(begin(happiness), end(happiness), greater<int>());

        // Initialize variables
        int i = 0;
        long long res = 0;

        // Iterate 'k' times to choose 'k' happiness values
        while(k--) {
            // Adjust the happiness value by subtracting its index 'i' if it's greater than 'i'
            happiness[i] = max(happiness[i] - i, 0);

            // Add the adjusted happiness value to the result
            res += happiness[i++];
        }

        // Return the maximum sum of happiness
        return res;
    }
};
/*
Time Complexity: O(n log n + k)
Space Complexity: O(n)
*/