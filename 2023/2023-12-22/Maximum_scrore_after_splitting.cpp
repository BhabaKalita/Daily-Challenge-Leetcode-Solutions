#include <iostream>
#include <vector>

class Solution {
public:
  int maxScore(std::string s) {
    // Initialize a variable to store the sum of '1's encountered
    int oneSum = 0;

    // Count the total number of '1's in the input string
    for (auto one : s) {
      if (one == '1')
        oneSum += 1;
    }

    // Initialize variables for the total score and the sum of '0's encountered
    int total = 0, zeroSum = 0;

    // Iterate through the string, calculating the total score at each position
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '0')
        zeroSum += 1;
      else
        oneSum--;

      // Update the total score by taking the maximum of the current total and
      // the sum of '1's and '0's
      total = std::max(total, oneSum + zeroSum);
    }

    // Return the final total score
    return total;
  }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/