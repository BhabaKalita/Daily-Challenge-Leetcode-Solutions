class Solution {
public:
    long minEnd(int n, int x) {
        long result = x;                // Initialize `result` to the value of `x`
        long remaining = n - 1;         // Set `remaining` to `n - 1`, which will be used to control the setting of bits
        long position = 1;              // `position` will be used to track the current bit position (starting from the least significant bit)
        
        // Loop until all bits in `remaining` have been processed
        while (remaining) {
            // Check if the current bit position in `x` is not set (0)
            if (!(x & position)) {
                // If the current bit in `remaining` is set (1), set this bit in `result`
                result |= (remaining & 1) * position;
                
                // Right-shift `remaining` to move to the next bit
                remaining >>= 1;
            }
            // Left-shift `position` to move to the next higher bit
            position <<= 1;
        }
        
        // Return the modified `result`, which meets the specified conditions
        return result;
    }
};
/*
  Time Complexity : O(logn)
  Space Complexity : O(1)
*/
