class Solution {
public:
    int lengthOfLastWord(string s) {
        // Initialize variables
        int len = s.size() - 1; // Length of the string
        int ans = 0; // Length of the last word

        // Trim trailing spaces
        while (len >= 0 && s[len] == ' ')
            len--;

        // Calculate length of last word
        while (len >= 0 && s[len] != ' ') {
            ans++;
            len--;
        }
        return ans; // Return length of last word
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/