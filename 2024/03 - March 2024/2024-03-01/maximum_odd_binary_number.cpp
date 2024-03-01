#include <string> // Include necessary header for string operations

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // Initialize variables to count the occurrences of '1' and '0'
        int cnt1 = 0, cnt0 = 0;

        // Iterate through each character in the input string
        for (char c : s) {
            // If the character is '1', increment the count of '1's
            if (c == '1')
                cnt1++;
            // If the character is '0', increment the count of '0's
            if (c == '0')
                cnt0++;
        }

        // Construct the maximum odd binary number based on the counts of '1's and '0's
        // One less '1' than the count of '1's, followed by the count of '0's, and a '1' to make it odd
        return string(cnt1 - 1, '1') + string(cnt0, '0') + '1';
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/