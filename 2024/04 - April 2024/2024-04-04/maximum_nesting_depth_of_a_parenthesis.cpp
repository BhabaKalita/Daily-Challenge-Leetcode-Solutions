class Solution {
public:
    int maxDepth(string s) {
        int res = 0, cur = 0; // Initialize result and current depth counter

        // Iterate through each character in the string
        for (char &val : s) {
            if (val == '(')
                res = max(res, ++cur); // If opening bracket found, increment current depth and update result if needed

            if (val == ')')
                --cur; // If closing bracket found, decrement current depth
        }
        return res; // Return the maximum depth found
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/