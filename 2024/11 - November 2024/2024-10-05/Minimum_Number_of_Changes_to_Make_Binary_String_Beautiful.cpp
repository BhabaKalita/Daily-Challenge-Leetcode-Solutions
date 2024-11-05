class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int count = 0, change = 0;

        char ch = s[0]; // Initialize the current character

        for (int i = 0; i < n; i++) {
            // If the current character is the same as the previous one, increment the count
            if (ch == s[i]) {
                count++;
                continue;
            }

            // If the count of the previous character is even, we can change it to the current character without increasing the total changes.
            // If the count is odd, we need to make one extra change to balance the count.
            if (count % 2 == 0) {
                count = 1; // Reset the count for the new character
            } else {
                change += 1; // Increment the total changes
                count = 0; // Reset the count for the new character
            }

            ch = s[i]; // Update the current character
        }

        return change;
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(1)
*/
