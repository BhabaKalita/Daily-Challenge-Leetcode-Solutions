#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        // Initialize a vector to store the rearranged array
        vector<int> ans(n, 0);
        // Initialize two pointers: one for positive numbers and one for negative numbers
        int indx = 0, neidx = 1;

        // Iterate through the input array
        for (auto x : nums) {
            // If the current number is positive, place it at the even index
            if (x > 0) {
                ans[indx] = x;
                indx += 2;
            }
            // If the current number is negative, place it at the odd index
            if (x < 0) {
                ans[neidx] = x;
                neidx += 2;
            }
        }
        // Return the rearranged array
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/