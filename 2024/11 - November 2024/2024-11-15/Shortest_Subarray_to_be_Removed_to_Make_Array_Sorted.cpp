class Solution {
public:
    // Function to find the length of the shortest subarray to remove 
    // so that the remaining array is sorted in non-decreasing order
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array

        // Step 1: Find the rightmost point `j` where the array is non-decreasing from the end
        int j = n - 1;
        while (j > 0 && arr[j] >= arr[j - 1]) {
            j--;
        }

        // If the entire array is already non-decreasing, we don't need to remove any subarray
        if (j == 0) return 0;

        int i = 0;         // Start pointer for left part
        int res = j;       // Initialize the result with removing the subarray [0, j)

        // Step 2: Iterate over the left part of the array, expanding it until `i`
        while (i < j && (i == 0 || arr[i] >= arr[i - 1])) {
            // Adjust `j` to find the earliest valid point where arr[i] <= arr[j]
            while (j < n && arr[i] > arr[j]) {
                j++;
            }

            // Calculate the length of the subarray to remove and update the minimum result
            res = min(res, j - i - 1);
            i++;
        }

        return res;  // Return the length of the shortest subarray to remove
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(1)
*/
