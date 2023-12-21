#include <algorithm>
#include <vector>

class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>> &points) {
    // Sort the points based on their x-coordinates
    sort(points.begin(), points.end());

    int ans = 0;

    // Iterate through sorted points to find the maximum difference between
    // consecutive x-coordinates
    for (int i = 1; i < points.size(); i++) {
      ans = max(ans, points[i][0] - points[i - 1][0]);
    }

    return ans;
  }
};

/*
Time Complexity: O(NlogN)
Space Complexity: O(1)
*/