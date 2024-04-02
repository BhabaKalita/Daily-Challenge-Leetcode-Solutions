#include <unordered_map>
#include <string>

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Create two unordered maps to store mappings from characters in s to characters in t, and vice versa
        unordered_map<char, char> m1, m2;

        // Iterate through each character in the strings
        for (int i = 0; i < s.size(); i++) {
            // If the characters at index i in both strings have not been mapped yet
            if (!m1[s[i]] && !m2[t[i]]) {
                // Map the character from s to the corresponding character in t, and vice versa
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            } else {
                // If either of the characters has been mapped before
                // Check if the mappings are consistent
                if (m1[s[i]] != t[i] || m2[t[i]] != s[i])
                    return false;
            }
        }
        // If all characters in s can be mapped to corresponding characters in t, return true
        return true;
    }
};
/*
Time Complexity : O(n)
Space Complexity : O(n)
*/