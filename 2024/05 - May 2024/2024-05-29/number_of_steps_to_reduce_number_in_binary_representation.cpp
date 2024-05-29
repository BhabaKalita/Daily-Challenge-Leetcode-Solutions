class Solution {
public:
    int numSteps(string &s) {
        int ones = 0;       // Count of '1's in the string
        int last_one = 0;   // Position of the last '1' in the string

        // Iterate over the string starting from the second character
        for (auto i = 1; i < s.size(); ++i) {
            if (s[i] == '1') {
                last_one = i;  // Update the position of the last '1'
                ++ones;        // Increment the count of '1's
            }
        }

        // Calculate the number of steps required
        return s.size() - 1 + (last_one - ones) + (last_one ? 2 : 0);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/