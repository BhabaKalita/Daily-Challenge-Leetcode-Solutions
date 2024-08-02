class Solution {
public:
    // Function to find the minimum number of swaps required to group all 1's together in a circular array.
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Count the total number of 1's in the array.
        int countOnes = accumulate(nums.begin(), nums.end(), 0);

        // Initialize pointers and counters for the sliding window.
        int i = 0, j = 0, currCount = 0, maxCount = 0;

        // Iterate over the array with a sliding window of size up to 2*n to simulate circular array behavior.
        while (j < 2 * n) {
            // Increase the count of 1's in the current window if the current element is 1.
            if (nums[j % n] == 1)
                currCount++;

            // If the window size exceeds the total number of 1's, slide the window.
            if (j - i + 1 > countOnes) {
                // Decrease the count of 1's by removing the element at the start of the window.
                currCount -= nums[i % n];
                i++;
            }

            // Update the maximum count of 1's in any window of size equal to countOnes.
            maxCount = max(maxCount, currCount);
            j++;
        }

        // The minimum swaps required is the difference between the total 1's and the maximum 1's found in any window of size countOnes.
        return countOnes - maxCount;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)