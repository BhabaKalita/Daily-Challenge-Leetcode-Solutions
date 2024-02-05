#include <unordered_map>
#include <string>

class Solution {
public:
    int firstUniqChar(string s) {
        // Create an unordered map to store the frequency of each character in the string
        unordered_map<char, int> mp;

        // Iterate through the string and update the frequency in the map
        for (auto x : s) {
            mp[x]++;
        }

        // Iterate through the string again to find the first non-repeating character
        for (int i = 0; i < s.size(); i++) {
            // If the frequency of the character is 1, return its index
            if (mp[s[i]] == 1)
                return i;
        }

        // If no non-repeating character is found, return -1
        return -1;
    }
};

/*
Time Complexity: O(n), where N is the length of the string.
Space Complexity: O(U), where U is the number of unique characters in the string.
*/