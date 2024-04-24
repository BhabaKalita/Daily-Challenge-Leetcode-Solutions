class Solution {
public:
    int tribonacci(int n) {
        // If n is less than 2, return n
        if (n < 2) 
            return n;

        // Initial values for tribonacci sequence
        int a = 0, b = 1, c = 1, d = a + b + c;

        // Loop until n becomes 2 or less
        while (n-- > 2) {
            // Calculate the next tribonacci number
            d = a + b + c;
            // Update values for next iteration
            a = b;
            b = c;
            c = d;
        }
        // Return the nth tribonacci number
        return c;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/