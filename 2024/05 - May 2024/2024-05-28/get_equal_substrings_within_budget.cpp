class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int n = s.length();  // Get the length of the input strings
        int i = 0;           // Initialize the start of the window
        int j;               // Initialize the end of the window

        // Iterate over the characters of the strings
        for (j = 0; j < n; ++j) {
            // Decrease k by the absolute difference between the characters of s and t at position j
            k -= abs(s[j] - t[j]);

            // If k is less than 0, move the start of the window to the right
            if (k < 0) {
                // Increase k by the absolute difference between the characters of s and t at position i
                k += abs(s[i] - t[i]);
                i++;  // Move the start of the window to the right
            }
        }

        // The length of the longest substring is the difference between j and i
        return j - i;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/