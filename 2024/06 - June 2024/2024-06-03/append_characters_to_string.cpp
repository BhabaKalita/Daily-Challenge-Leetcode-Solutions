class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_index = 0, t_index = 0;
        int s_length = s.length(), t_length = t.length();

        // Iterate through both strings to find matching characters
        while (s_index < s_length && t_index < t_length) {
            if (s[s_index] == t[t_index]) {
                t_index++;  // Move to the next character in t if there is a match
            }
            s_index++;  // Always move to the next character in s
        }

        // Return the number of characters in t that are not matched in s
        return t_length - t_index;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/