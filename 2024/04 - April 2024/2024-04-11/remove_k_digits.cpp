class Solution {
public:
    string removeKdigits(string num, int k) {
        // If no digits need to be removed, return the number as is
        if (k == 0) return num;

        stack<char> s; // Stack to store the digits
        string res = ""; // Result string

        // If the number of digits to remove is greater than or equal to the size of the number,
        // then the resulting number will be 0
        if (num.size() <= k) return "0";

        // Iterate through each digit in the number
        for (char c : num) {
            // While there are still digits to remove, and the current digit is smaller than the top of the stack
            while (k > 0 && !s.empty() && c < s.top()) {
                --k; // Decrement the count of digits to remove
                s.pop(); // Remove the top digit from the stack
            }
            s.push(c); // Push the current digit onto the stack

            // If the stack only contains a single digit '0', pop it
            if (s.size() == 1 && c == '0')
                s.pop();
        }

        // After processing all digits, if there are still digits to remove, remove them
        while (k && !s.empty()) {
            --k;
            s.pop();
        }

        // Construct the result string by popping digits from the stack
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }

        // Reverse the result string to get the correct order of digits
        reverse(res.begin(), res.end());

        // If the result string is empty, return "0"
        if (res.size() == 0)
            return "0";

        return res; // Return the resulting number
    }
};

/*
Time Complexity : O(n)
Space Complexity : O(n)
*/