class Solution {
public:
    // Function to check if a number is a power of two
    bool isPowerOfTwo(int n) {
        // If n is less than or equal to 0, it cannot be a power of two
        if(n <= 0)
            return false;

        // Bitwise AND of n and (n - 1) will be 0 if n is a power of two
        // Explanation: In binary representation, a power of two has only one bit set to 1.
        // Subtracting 1 from it will flip all bits to the right of the rightmost set bit,
        // and leave the rightmost set bit unchanged.
        // If n is a power of two, the result will be 0 after the bitwise AND operation.
        return ((n & (n - 1)) == 0);
    }
};

/*
Time Complexity: O(1)
Space Complexity: O(1)
*/