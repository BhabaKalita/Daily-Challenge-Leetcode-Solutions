#include <set>
#include <string>
#include <utility>

class Solution {
public:
  /**
   * Check if the given path crosses itself.
   * @param path The input path as a string containing directions (N, S, E, W).
   * @return True if the path crosses itself, false otherwise.
   */
  bool isPathCrossing(string path) {
    // Set to store visited points
    set<pair<int, int>> temp;

    // Initial position
    int x = 0, y = 0;
    temp.insert({0, 0});

    // Traverse the path
    for (char ch : path) {
      // Update the position based on the current direction
      if (ch == 'N')
        ++y;
      else if (ch == 'S')
        --y;
      else if (ch == 'E')
        ++x;
      else
        --x;

      // Check if the current position has been visited before
      if (!temp.insert({x, y}).second)
        return true;
    }

    // If no crossing is found
    return false;
  }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
