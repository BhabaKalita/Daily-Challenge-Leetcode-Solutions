#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  // Function to find the destination city from a list of paths
  string destCity(vector<vector<string>> &paths) {
    // Create an unordered set to store the starting cities
    unordered_set<string> temp;

    // Get the number of paths
    int n = paths.size();

    // Iterate through the paths and insert starting cities into the set
    for (int i = 0; i < n; i++) {
      temp.insert(paths[i][0]);
    }

    // Iterate through the paths again to find the destination city
    for (int i = 0; i < n; i++) {
      // If the destination city is not in the set of starting cities, return it
      if (temp.find(paths[i][1]) == temp.end())
        return paths[i][1];
    }

    // If no destination city is found, return an empty string
    return "";
  }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
