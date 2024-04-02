#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Result vector to store groups of anagrams
        vector<vector<string>> res;

        // Map to store anagrams grouped by their sorted forms
        unordered_map<string, vector<string>> mp;

        // Iterate through each string in the input vector
        for(auto &s : strs) {
            // Create a copy of the string and sort it
            string t = s;
            sort(t.begin(), t.end());

            // Add the original string to its corresponding group in the map
            mp[t].push_back(s);
        }

        // Iterate through the map and push groups of anagrams to the result vector
        for(auto i = mp.begin(); i != mp.end(); i++) {
            res.push_back(i->second);
        }

        // Return the final result containing groups of anagrams
        return res;
    }
};

/*
Time Complexity: O(N * M * log(M)), where N is the number of strings and M is the maximum length of a string.
Space Complexity: O(N * M), where N is the number of strings and M is the maximum length of a string
*/
