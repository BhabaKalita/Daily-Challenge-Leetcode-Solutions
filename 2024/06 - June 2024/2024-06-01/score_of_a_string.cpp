class Solution {
public:
    // Function to calculate the score of a string based on the absolute differences of adjacent characters
    static int scoreOfString(string& s) {
        // Compute the difference between adjacent characters and store the result in the same string
        adjacent_difference(s.begin(), s.end(), s.begin());

        // Accumulate the absolute values of the differences, starting from the second element
        return accumulate(s.begin() + 1, s.end(), 0, [](int x, int y) {
            return x + abs(y);
        });
    }
};

/*
Time Complexity:
- The time complexity is O(n), where n is the length of the string s.
- This is because the `adjacent_difference` function takes O(n) time to compute the differences.
- The `accumulate` function also takes O(n) time to sum the absolute differences.

Space Complexity:
- The space complexity is O(1) additional space.
- This is because the operations are performed in-place on the input string s, and only a constant amount of extra space is used for temporary variables.
*/