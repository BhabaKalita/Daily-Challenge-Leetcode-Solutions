#include <iostream>
#include <string>

class Solution {
public:
    int minOperations(std::string s) {
        int count = 0; // Initialize a counter for operations
        int len = s.size(); // Get the length of the string

        // Iterate through each character in the string
        for (int i = 0; i < len; i++) {
            // Check if the current character's numeric value is not equal to i%2
            // This condition checks if the character should be flipped to make the sequence alternating
            if (s[i] - '0' != i % 2) {
                count++; // Increment the counter for each operation needed
            }
        }

        // Return the minimum of operations to make the sequence 0101... or 1010...
        return std::min(count, len - count);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
