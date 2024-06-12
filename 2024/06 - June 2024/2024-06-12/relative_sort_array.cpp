class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        int i = 0, j = 0, k = n - 1; // Initialize pointers

        // Loop until the middle pointer (j) passes the right pointer (k)
        while (j <= k) {
            if (nums[j] == 1) {
                // If current element is 1, just move the middle pointer
                j++;
            } else if (nums[j] == 2) {
                // If current element is 2, swap it with the element at the right pointer
                swap(nums[j], nums[k]);
                k--; // Decrement the right pointer
                // Do not increment j here because we need to check the element swapped from the end
            } else {
                // If current element is 0, swap it with the element at the left pointer
                swap(nums[i], nums[j]);
                i++; // Increment the left pointer
                j++; // Increment the middle pointer since the swapped element is processed
            }
        }
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/