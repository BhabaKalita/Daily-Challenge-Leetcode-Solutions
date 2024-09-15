class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Create a vector to store the indices of the first occurrences of different vowel combinations.
        vector<int> mapy(32, -2);

        // Initialize the first element to -1 for the case of no vowels in the initial substring.
        mapy[0] = -1;

        // Declare a variable to store the maximum length of the substring found so far.
        int maxLen = 0;

        // Declare a variable to represent the current combination of vowels encountered.
        int mask = 0;

        // Iterate over each character in the input string.
        for (int i = 0; i < s.size(); ++i) {
            // Extract the current character from the string.
            char ch = s[i];

            // Update the mask based on the current character to indicate the presence of the vowel.
            switch (ch) {
                case 'a':
                    mask ^= 1;
                    break;
                case 'e':
                    mask ^= 2;
                    break;
                case 'i':
                    mask ^= 4;
                    break;
                case 'o':
                    mask ^= 8;
                    break;
                case 'u':
                    mask ^= 16;
                    break;
            }

            // Get the previous index associated with the current mask.
            int prev = mapy[mask];

            // If the mask has not been encountered before, record the current index.
            if (prev == -2) {
                mapy[mask] = i;
            } else {
                // If the mask has been encountered before, calculate the length of the current substring and update the maximum length if necessary.
                maxLen = max(maxLen, i - prev);
            }
        }

        // Return the maximum length of the longest substring containing vowels.
        return maxLen;
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(1)
*/
