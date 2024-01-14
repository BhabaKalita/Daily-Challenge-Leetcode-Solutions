#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Initialize arrays to store the frequency of each character in both words
        vector<int> w1(26, 0), w2(26, 0), w3(26, 0), w4(26, 0);

        // Iterate through the characters of the first word
        for (char c : word1) {
            w1[c - 'a']++;     // Increment frequency count
            w3[c - 'a'] = 1;    // Mark the presence of the character in w3
        }

        // Iterate through the characters of the second word
        for (char c : word2) {
            w2[c - 'a']++;     // Increment frequency count
            w4[c - 'a'] = 1;    // Mark the presence of the character in w4
        }

        // Sort the frequency arrays for comparison
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());

        // Check if the sorted frequency arrays and presence arrays are equal
        return w1 == w2 && w3 == w4;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/