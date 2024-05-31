class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Pass 1:
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

        // Get its last set bit using unsigned integer to avoid overflow issues
        unsigned int lastSetBit = diff & -static_cast<unsigned int>(diff);

        // Pass 2:
        vector<int> rets = {0, 0}; // This vector stores the two numbers we will return
        for (int num : nums) {
            if ((num & lastSetBit) == 0) { // The bit is not set
                rets[0] ^= num;
            } else { // The bit is set
                rets[1] ^= num;
            }
        }
        return rets;
    }
};

/*
Time Complexity:
- The time complexity is O(n), where n is the number of elements in the input vector `nums`.
- This is because we make two passes over the array: one for calculating the XOR (O(n)) and one for segregating and XORing the numbers based on the last set bit (O(n)).

Space Complexity:
- The space complexity is O(1).
- This is because we are using a constant amount of extra space (a few integer variables and a vector of size 2).
*/
