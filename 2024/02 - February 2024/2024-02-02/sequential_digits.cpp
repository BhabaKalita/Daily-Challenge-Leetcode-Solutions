#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to generate sequential digits within the given range [low, high].
    vector<int> sequentialDigits(int low, int high) {
        // Define a string containing all digits from 1 to 9.
        string c = "123456789";

        // Vector to store the generated sequential digits.
        vector<int> a;

        // Nested loops to generate all possible substrings and convert them to integers.
        for (int i = 0; i < c.size(); i++) {
            for (int j = i + 1; j <= c.size(); j++) {
                // Convert the substring to an integer.
                int curr = stoi(c.substr(i, j - i));

                // Check if the generated number is within the specified range.
                if (curr <= high && curr >= low)
                    a.push_back(curr); // Add the number to the result vector.
            }
        }

        // Sort the result vector in ascending order.
        sort(a.begin(), a.end());

        // Return the vector containing sequential digits within the specified range.
        return a;
    }
};

// Time Complexity:
// The time complexity of this solution is O(1) because the size of the string c is constant (9 digits).
// The nested loops iterate over a fixed number of elements, and the stoi function has constant time complexity.

// Space Complexity:
// The space complexity is O(1) as the size of the result vector 'a' is not dependent on the input size.
// The string 'c' also has a constant size. The space required is mainly for the result vector.
