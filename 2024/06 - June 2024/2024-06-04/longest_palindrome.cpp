class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0; // Variable to count characters with an odd frequency

        // Iterate over all possible characters from 'A' to 'z'
        for (char c = 'A'; c <= 'z'; c++) {
            // Count the occurrences of the current character in the string
            odd += count(s.begin(), s.end(), c) & 1;
        }

        // The longest palindrome length is the size of the string minus the odd count
        // plus one if there is at least one odd character (to place in the center)
        return s.size() - odd + (odd > 0);
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/