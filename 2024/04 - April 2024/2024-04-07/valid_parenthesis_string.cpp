class Solution {
public:
    bool checkValidString(string s) {
        // Initialize counters for the maximum and minimum number of open parentheses
        int cmax = 0, cmin = 0;

        // Iterate through each character in the string
        for(char c : s) {
            // If the character is an opening parenthesis '('
            if(c == '(')
                cmax++, cmin++; // Increment both cmax and cmin
            // If the character is a closing parenthesis ')'
            if(c == ')')
                cmax--, cmin = max(cmin - 1, 0); // Decrement cmax and update cmin by taking the maximum of cmin-1 and 0
            // If the character is an asterisk '*'
            if(c == '*')
                cmax++, cmin = max(cmin - 1, 0); // Increment cmax and update cmin by taking the maximum of cmin-1 and 0

            // If at any point cmax becomes negative, return false
            if(cmax < 0)
                return false;
        }

        // Check if the minimum number of open parentheses is 0
        return cmin == 0;
    }
};

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/