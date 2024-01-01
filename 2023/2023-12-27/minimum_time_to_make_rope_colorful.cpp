#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // Function to calculate the minimum cost
  int minCost(string colors, vector<int> &neededTime) {
    // Initialize variables to keep track of the total cost, maximum cost, and
    // result
    int sum_cost = 0, max_cost = 0;
    int n = colors.size(), res = 0;

    // Iterate through the given colors and neededTime arrays
    for (int i = 0; i < n; i++) {
      // Check if the current color is different from the previous one
      if (i > 0 && colors[i] != colors[i - 1]) {
        // Add the accumulated cost for the previous color to the result
        res += sum_cost - max_cost;
        // Reset the sum_cost and max_cost for the new color
        sum_cost = max_cost = 0;
      }

      // Update the sum_cost with the time needed for the current color
      sum_cost += neededTime[i];
      // Update the max_cost with the maximum time needed for the current color
      max_cost = max(max_cost, neededTime[i]);
    }

    // Add the final accumulated cost for the last color to the result
    res += sum_cost - max_cost;
    // Return the overall minimum cost
    return res;
  }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/