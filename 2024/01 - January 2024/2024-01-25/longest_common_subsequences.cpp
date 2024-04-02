#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // Function to solve the problem using tabulation (bottom-up dynamic programming)
    int solveTab(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // Create two vectors to store the current and next rows of the dynamic programming table
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        // Iterate through the strings in reverse order to fill the dynamic programming table
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                int len1 = 0;

                // Check if the characters at the current positions match
                if(text1[i] == text2[j])
                    len1 = 1 + next[j+1];  // If they match, extend the length by 1
                else {
                    // If they don't match, choose the maximum length from the adjacent cells
                    len1 = max(next[j], curr[j+1]);
                }

                // Update the current row with the calculated length
                curr[j] = len1;clear
            }

            // Update the next row with the current row
            next = curr;
        }

        // The result is stored in the top-left cell of the table
        return next[0];
    }

    // Function to find the length of the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        return solveTab(text1, text2);
    }
};

// Time Complexity: O(m * n), where m is the length of text1 and n is the length of text2
// Space Complexity: O(min(m, n)), as only two rows of the dynamic programming table are used at a time
