class Solution {
public:
    int findComplement(int num) {
        // Base case: If the input number is 0, its complement is 1.
        if (num == 0) return 1;

        // Initialize a mask with all bits set to 1.
        unsigned int mask = ~0;

        // While the current bit of `num` is 1, shift the mask to the left.
        while (num & mask) {
            mask <<= 1;
        }

        // Calculate the complement by inverting both the mask and the original number,
        // and then performing a bitwise AND operation.
        return ~mask & ~num;
    }
};
// Time Complexity: O(1)
// Space Complexity: O(1)