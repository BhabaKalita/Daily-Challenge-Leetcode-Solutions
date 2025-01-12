class Solution {
public:
    // Function to determine if the given string can form a valid parentheses sequence
    bool canBeValid(string s, string locked) {
        int n = s.size();  // Get the length of the string

        // If the length of the string is odd, it's impossible to have a valid sequence
        if(n % 2 == 1)  
            return false;

        // Left to right pass: count the open parentheses
        int openB = 0;
        for(int i = 0; i < n; i++) {
            // If we encounter an open parenthesis or an unlocked character (locked[i] == '0'),
            // treat it as an open parenthesis (since it can be replaced with one).
            if(s[i] == '(' || locked[i] == '0')
                openB++;
            else  // Otherwise, it's a closing parenthesis
                openB--;

            // If at any point, the number of closing parentheses exceeds the number of open parentheses,
            // the sequence is invalid, so return false
            if(openB < 0)
                return false;
        }

        // Right to left pass: count the closing parentheses
        int closeB = 0;
        for(int j = n - 1; j >= 0; j--) {
            // If we encounter a closing parenthesis or an unlocked character (locked[j] == '0'),
            // treat it as a closing parenthesis (since it can be replaced with one).
            if(s[j] == ')' || locked[j] == '0')
                closeB++;
            else  // Otherwise, it's an open parenthesis
                closeB--;

            // If at any point, the number of open parentheses exceeds the number of closing parentheses,
            // the sequence is invalid, so return false
            if(closeB < 0)
                return false;
        }

        // If we pass both checks, return true as the sequence is valid
        return true;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
