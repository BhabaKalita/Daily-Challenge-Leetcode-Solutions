class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // If either m or n is zero, return 0
        if (m == 0 || n == 0)
            return 0;

        // If the positions of the leftmost set bits in m and n are different, return 0
        if ((int)log2(m) != (int)log2(n))
            return 0;

        // Initialize the result with m
        int res = m;

        // Iterate through each number in the range from m to n
        for (int x = m; x <= n; x++) {
            // Update the result by performing bitwise AND with x
            res &= x;
        }

        // Return the final result
        return res;
    }
};
/*
Time Complexity: O(n+log(n))
Space Complexity: O(1)
*/