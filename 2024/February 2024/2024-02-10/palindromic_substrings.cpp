#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), ans = 0; // Length of string and initialization of answer
        for (int i = 0; i < n; ++i) {
            int even = palindromeCount(s, i, i + 1); // Count palindromic substrings with even length
            int odd = palindromeCount(s, i, i);      // Count palindromic substrings with odd length
            ans += even + odd;                       // Update answer with counts
        }
        return ans; // Return total count of palindromic substrings
    }

    // Function to count palindromic substrings with given center(s)
    int palindromeCount(const string& s, int left, int right) {
        int count = 0; // Initialize count of palindromic substrings
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;     // Expand towards left
            ++right;    // Expand towards right
            ++count;    // Increment count for each palindrome found
        }
        return count;   // Return count of palindromic substrings
    }
};
/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/