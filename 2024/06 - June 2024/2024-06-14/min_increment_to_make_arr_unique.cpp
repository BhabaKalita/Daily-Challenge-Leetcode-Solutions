class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        // Sort the input array to process elements in ascending order
        sort(A.begin(), A.end());

        int res = 0; // Initialize the result to store the total increments needed
        int need = 0; // This variable stores the next needed unique value

        // Iterate over each element in the sorted array
        for (auto x : A) {
            // Calculate the increments needed to make 'x' at least 'need'
            // If 'x' is already greater than or equal to 'need', max(need-x, 0) will be 0
            // Otherwise, add the difference (need - x) to the result
            res += max(need - x, 0);

            // Update 'need' to be one more than the current value or the value of 'x' + 1
            // This ensures that the next value to be considered unique is 'need'
            need = max(need, x) + 1;
        }

        return res; // Return the total increments needed
    }
};

/**
Time Complexity: O(n log n)
Space Complexity: O(1)
*/