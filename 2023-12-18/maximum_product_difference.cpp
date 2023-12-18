class Solution {
public:
  int maxProductDifference(vector<int> &nums) {
    // Initialize variables for first and second highest, and first and second
    // lowest
    int firstH = INT_MIN, secondH = INT_MIN, firstL = INT_MAX,
        secondL = INT_MAX;
    int n = nums.size(); // Get the size of the vector

    // Find the first and second highest elements
    for (int i = 0; i < n; ++i) {
      if (nums[i] > firstH) {
        secondH = firstH;
        firstH = nums[i];
      } else if (nums[i] > secondH) {
        secondH = nums[i];
      }
    }

    // If all elements are the same, set secondH to firstH
    if (secondH == INT_MIN)
      secondH = firstH;

    // Find the first and second lowest elements
    for (int i = 0; i < n; ++i) {
      if (nums[i] < firstL) {
        secondL = firstL;
        firstL = nums[i];
      } else if (nums[i] < secondL) {
        secondL = nums[i];
      }
    }

    // If all elements are the same, set secondL to firstL
    if (secondL == INT_MAX)
      secondL = firstL;

    // Calculate and return the result
    return (firstH * secondH) - (firstL * secondL);
  }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/