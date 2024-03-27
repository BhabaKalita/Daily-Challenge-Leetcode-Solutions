class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // If k is 0, no subarray can have a product less than it
        if (k == 0) 
            return 0;

        int cnt = 0; // Counter to keep track of valid subarrays
        int pro = 1; // Variable to store the product of elements in the current subarray

        // Two pointers technique: i and j define the current subarray
        for (int i = 0, j = 0; j < nums.size(); j++) {
            pro *= nums[j]; // Update the product by multiplying with the next element

            // Shrink the subarray from the left until product is less than k
            while (i <= j && pro >= k) {
                pro /= nums[i++]; // Divide by the leftmost element and move the left pointer
            }

            // Count all valid subarrays ending at j
            cnt += j - i + 1;
        }

        return cnt; // Return the count of valid subarrays
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/