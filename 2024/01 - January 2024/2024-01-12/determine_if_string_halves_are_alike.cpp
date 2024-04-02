#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        // Define a string containing all vowels (both lowercase and uppercase)
        string vowels = "aeiouAEIOU";

        // Initialize variables
        int ans = 0, n = s.size();

        // Iterate through the first half and its corresponding second half of the string
        for(int i = 0, j = n / 2; i < n / 2; i++, j++) {
            // Check if the character at index i in the first half is a vowel
            if (~vowels.find(s[i])) {
                ans++; // Increment count if it is a vowel
            }

            // Check if the character at index j in the second half is a vowel
            if (~vowels.find(s[j])) {
                ans--; // Decrement count if it is a vowel
            }
        }

        // Return true if the count of vowels in both halves is equal, otherwise false
        return ans == 0;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/