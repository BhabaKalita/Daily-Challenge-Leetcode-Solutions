class Solution {
public:
    bool canMakeSubsequence(string source, string target) {
        int targetIdx = 0; // Pointer to track the current character in the target string
        int targetLen = target.length(); // Length of the target string
        
        // Iterate through each character in the source string
        for (char currChar : source) {
            // Check if the target pointer is within bounds
            // and the current character in `source` can match the current character in `target`
            // either directly (target[targetIdx] == currChar) or after a cyclic increment
            if (targetIdx < targetLen && (target[targetIdx] - currChar + 26) % 26 <= 1) {
                targetIdx++; // Move to the next character in `target`
            }
        }
        
        // If we've matched all characters in the target string, return true
        return targetIdx == targetLen;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)
