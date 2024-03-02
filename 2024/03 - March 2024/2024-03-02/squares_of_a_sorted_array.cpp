#include <vector> // Include necessary header for vector

class Solution {
public:
    // Function to square each element of the input vector, sort the squared values in non-decreasing order, and return the result
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(); // Store the size of the input vector
        int i = 0, j = n - 1; // Initialize two pointers, one pointing to the beginning of the vector and the other to the end
        vector<int> res(n); // Initialize a vector to store the result

        // Iterate through the vector in reverse order to fill the result vector with squared values in non-decreasing order
        for (int k = n - 1; k >= 0; k--) {
            // Compare the absolute values of elements pointed by i and j
            if (abs(nums[i]) > abs(nums[j])) {
                // If the absolute value of nums[i] is greater, square it and increment i
                res[k] = nums[i] * nums[i++];
            } else {
                // If the absolute value of nums[j] is greater or equal, square it and decrement j
                res[k] = nums[j] * nums[j--];
            }
        }
        // Return the result vector
        return res;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/