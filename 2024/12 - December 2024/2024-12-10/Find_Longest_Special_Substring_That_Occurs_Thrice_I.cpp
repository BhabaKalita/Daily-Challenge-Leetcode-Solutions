class Solution {
public:
    int maximumLength(string s) {
        int n = s.size(); // Length of the input string
        int l = 1, r = n; // Binary search range for substring length

        // Check if there is any "special" substring with length at least 1
        if (!helper(s, n, l)) return -1;

        // Binary search to find the maximum length of the "special" substring
        while (l + 1 < r) {
            int mid = (l + r) / 2; // Midpoint of the current range
            // If there exists a "special" substring of length `mid`
            if (helper(s, n, mid)) 
                l = mid; // Move to the right half
            else 
                r = mid; // Move to the left half
        }

        return l; // The maximum valid length
    }

private:
    // Helper function to check if there exists a "special" substring of length `x`
    bool helper(const string& s, int n, int x) {
        vector<int> cnt(26, 0); // Count of valid substrings for each character
        int p = 0; // Pointer to track the start of the current substring

        // Iterate through the string
        for (int i = 0; i < n; i++) {
            // Move the pointer `p` to ensure `s[p] == s[i]`
            while (s[p] != s[i]) 
                p++;
            // If the length of the current "special" substring is at least `x`
            if (i - p + 1 >= x) 
                cnt[s[i] - 'a']++; // Increment the count for the current character
            // If any character has more than 2 valid substrings, return true
            if (cnt[s[i] - 'a'] > 2) 
                return true;
        }

        return false; // No valid substring of length `x` exists
    }
};
// Time Complexity: O(n⋅log⁡n)
// Space Complexity: O(1)
