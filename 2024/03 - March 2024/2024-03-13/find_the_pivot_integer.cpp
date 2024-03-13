class Solution {
public:
    int pivotInteger(int n) {
        // Calculate the sum of the first 'n' positive integers
        int sum = n * (n + 1) / 2;

        // Calculate the square root of the sum
        int x = sqrt(sum);

        // Check if the square of the square root equals the sum
        // If it does, then x is a pivot integer, return x
        // Otherwise, return -1 indicating no pivot integer
        return x * x == sum ? x : -1;
    }
};

/*
Time Complexity: O(1)
Space Complexity: O(1)
*/