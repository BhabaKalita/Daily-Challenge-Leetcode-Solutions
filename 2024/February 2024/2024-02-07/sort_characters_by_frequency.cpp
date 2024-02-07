#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Create a vector of pairs to store character frequencies
        vector<pair<int, char>> v;

        // Create a map to store character frequencies
        map<char, int> mp;

        // Count frequencies of characters in the string
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        // Populate the vector with pairs of frequencies and characters
        for (auto i : mp) {
            v.push_back({i.second, i.first});
        }

        // Sort the vector in descending order based on frequencies
        sort(v.rbegin(), v.rend());

        // Build the resulting string based on sorted frequencies
        string ans;
        for (auto i : v) {
            for (int j = 0; j < i.first; j++) {
                ans += i.second;
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(n + m log m), where n is the length of the input string and m is the number of unique characters.
Space Complexity: O(n + m)
*/