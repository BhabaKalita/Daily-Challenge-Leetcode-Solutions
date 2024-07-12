class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Initialize counters for 'a' and 'b'
        int aCount = 0;
        int bCount = 0;

        // Determine the smaller value between x and y
        int lesser = min(x, y);

        // Initialize the result which will store the total gain
        int result = 0;

        // Iterate through each character in the string s
        for (char c : s) {
            // If the character is not 'a' or 'b'
            if (c > 'b') {
                // Add the gain from any remaining pairs of 'a' and 'b'
                result += min(aCount, bCount) * lesser;

                // Reset the counters for 'a' and 'b'
                aCount = 0;
                bCount = 0;
            } else if (c == 'a') {
                // If 'a' is found and 'b' count is greater than 0 (form 'ba' or 'ab')
                if (x < y && bCount > 0) {
                    // Decrease bCount and add the value of y to the result
                    bCount--;
                    result += y;
                } else {
                    // Otherwise, increase the count of 'a'
                    aCount++;
                }
            } else { // When c == 'b'
                // If 'b' is found and 'a' count is greater than 0 (form 'ab' or 'ba')
                if (x > y && aCount > 0) {
                    // Decrease aCount and add the value of x to the result
                    aCount--;
                    result += x;
                } else {
                    // Otherwise, increase the count of 'b'
                    bCount++;
                }
            }
        }

        // Add the remaining gain from any remaining pairs of 'a' and 'b'
        result += min(aCount, bCount) * lesser;

        // Return the total gain
        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)