class Solution {
public:
    bool rotateString(string s, string goal) {
        // If the lengths of the two strings are different, they cannot be rotations of each other.
        if (s.length() != goal.length()) {
            return false;
        }

        // Concatenate s with itself to create a string containing all possible rotations of s.
        string concatenated = s + s;

        // Search for goal in the concatenated string. If found, goal is a rotation of s.
        return concatenated.find(goal) != string::npos;
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(n)
*/
