class Solution {
public:
    bool judgeSquareSum(int c) {
        // Define two pointers: one starting from 0 and the other from the square root of c.
        long left = 0;
        long right = sqrt(c);

        // Use a two-pointer technique to find if there exist two numbers whose squares sum to c.
        while (left <= right) {
            long sum = left * left + right * right; // Calculate the sum of squares of the two pointers.

            if (sum == c) // If the sum equals c, we found a valid pair.
                return true;
            else if (sum < c) // If the sum is less than c, increment the left pointer to increase the sum.
                left++;
            else // If the sum is greater than c, decrement the right pointer to decrease the sum.
                right--;
        }

        // If no valid pair is found, return false.
        return false;
    }
};
/*
Time Complexity: O(sqrt(c))
Space Complexity: O(1)
*/