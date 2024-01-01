#include <string>
#include <unordered_map>

class Solution {
public:
  // Function to find the maximum length between equal characters in a string
  int maxLengthBetweenEqualCharacters(string s) {
    // Map to store the last index of each character encountered
    unordered_map<char, int> mp;

    // Variable to store the maximum length between equal characters
    int ans = -1;

    // Loop through each character in the string
    for (int i = 0; i < s.size(); i++) {
      // If the character is already in the map, update the maximum length
      if (mp.find(s[i]) != mp.end()) {
        ans = max(ans, i - mp[s[i]] - 1);
      } else {
        // If the character is not in the map, add it with its current index
        mp[s[i]] = i;
      }
    }

    // Return the maximum length between equal characters
    return ans;
  }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
