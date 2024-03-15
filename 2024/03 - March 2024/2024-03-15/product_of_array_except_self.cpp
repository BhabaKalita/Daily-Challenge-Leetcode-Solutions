#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0); // Initialize a vector to store the results, initially filled with zeros
        ans[0] = 1; // First element of the result vector is set to 1

        // Calculating the products of elements to the left of each element
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1]; // Multiply the previous product by the corresponding element to the left
        }

        int right = 1;

        // Calculating the products of elements to the right of each element and combining it with the previously calculated products from the left
        for(int j = n - 1; j >= 0; j--) {
            ans[j] *= right; // Multiply the previously calculated product with the product of elements to the right
            right *= nums[j]; // Update the product of elements to the right
        }

        return ans; // Return the final result
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/