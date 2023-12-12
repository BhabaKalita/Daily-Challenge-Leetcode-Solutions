#include <vector>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int max1 = 0, max2 = 0;

    // Find the two largest elements
    for (int num : nums) {
      if (num > max1) {
        max2 = max1;
        max1 = num;
      } else if (num > max2) {
        max2 = num;
      }
    }

    // Calculate the maximum product
    return (max1 - 1) * (max2 - 1);
  }
};

/*
Time Compleixty: O(n)
Space Complexity: O(1)
*/