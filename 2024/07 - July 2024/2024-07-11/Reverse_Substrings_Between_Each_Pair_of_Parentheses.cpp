class Solution {
public:
    string reverseParentheses(string s) {
        // Call the helper function to process the string and return the result
        return helper(s);
    }

    // Global index to keep track of the current position in the string
    int i = 0;

    string helper(string& s) {
        string result;

        // Loop through the string starting from the current index
        while(i < s.length()) {

            if(s[i] == ')') {
                // If a closing parenthesis is encountered, reverse the current result and return
                i++;  // Move the index to the next character
                reverse(result.begin(), result.end());  // Reverse the current result
                return result;  // Return the reversed result
            } else if(s[i] == '(') {
                // If an opening parenthesis is encountered, recursively call helper
                i++;  // Move the index to the next character
                string st = helper(s);  // Recursively process the string inside the parentheses
                result += st;  // Append the processed string to the result
            } else {
                // If a regular character is encountered, append it to the result
                result += s[i];
                i++;  // Move the index to the next character
            }
        }

        // Return the final result
        return result;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)