class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        const int m = spaces.size(); // Number of spaces to insert
        int n = s.size(); // Length of the original string

        // Create a new string of size m + n (original string + number of spaces)
        // Initialized with spaces (' ')
        string t(m + n, ' '); 

        int j = 0; // Pointer for the `spaces` vector
        for (int i = 0; i < n; i++) { // Iterate through the original string
            // If the current index matches a position in `spaces` vector
            if (j < m && i == spaces[j]) {
                t[i + j] = ' '; // Insert a space at the corresponding position in `t`
                j++; // Move to the next space position
            }
            t[i + j] = s[i]; // Copy the current character from `s` to `t` at the correct position
        }

        return t; // Return the new string with spaces added
    }
};
// Time Complexity: O(n)
// Space Complexity: O(m+n)
