#include <string>
#include <vector>

class Solution {
public:
    string fractionAddition(string expression) {
        // Initialize variables for numerator and denominator
        int numerator = 0, denominator = 1;

        // Iterate through the expression character by character
        int i = 0, n = expression.size();
        while (i < n) {
            // Handle the sign (+ or -) of the current fraction
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                i++;
            }

            // Extract the numerator from the expression
            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;

            // Skip the '/' character
            i++;

            // Extract the denominator from the expression
            int den = 0;
            while (i < n && isdigit(expression[i])) {
                den = den * 10 + (expression[i] - '0');
                i++;
            }

            // Calculate the new numerator and denominator based on the current fraction
            numerator = numerator * den + num * denominator;
            denominator *= den;

            // Find the greatest common divisor (GCD) of the numerator and denominator
            int gcdVal = gcd(abs(numerator), denominator);

            // Simplify the fraction by dividing both numerator and denominator by the GCD
            numerator /= gcdVal;
            denominator /= gcdVal;
        }

        // Return the final fraction as a string
        return to_string(numerator) + "/" + to_string(denominator);
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(1)