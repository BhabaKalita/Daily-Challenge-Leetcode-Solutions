class Solution {
public:
    int minSteps(int n) {
        // If n is 1, no steps are needed as we already have 'A'.
        if(n == 1) return 0;

        int factor = 2; // Start checking from the smallest prime factor.
        int steps = 0;  // This will store the total number of steps.

        // Continue until n is reduced to 1.
        while(n > 1) {

            // If n is divisible by the current factor, add the factor to steps.
            // Then divide n by the factor.
            while(n % factor == 0) {
                steps += factor;
                n /= factor;
            }
            factor++; // Move to the next potential factor.
        }

        // Return the total number of steps needed.
        return steps;
    }
};
// Time Complexity: O(√n)
// Space Complexity: O(1)