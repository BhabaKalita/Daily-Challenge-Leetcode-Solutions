class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    // XOR all elements of A with k
    for (int a : nums)
        k ^= a;

    // Count the number of set bits in k using built-in function
    return __builtin_popcount(k);
    }
};

/*
Time Complexity: O(n + logk)
Space Complexity: O(1)
*/