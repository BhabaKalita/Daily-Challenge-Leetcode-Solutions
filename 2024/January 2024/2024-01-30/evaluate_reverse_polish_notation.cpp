#include <vector>
#include <stack>
#include <string>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Create a stack to hold operands
        stack<int> s;

        // Iterate through the tokens
        for (auto x : tokens) {
            // Check if the token is an operator
            if (x == "+" || x == "-" || x == "/" || x == "*") {
                int op = 0;

                // Ensure there are at least two operands in the stack
                if (!s.empty()) {
                    // Pop the top two operands
                    int op1 = s.top();
                    s.pop();

                    int op2 = s.top();
                    s.pop();

                    // Perform the operation based on the operator
                    if (x == "+") op = op1 + op2;
                    if (x == "-") op = op2 - op1;
                    if (x == "/") op = op2 / op1;
                    if (x == "*") op = op1 * op2;
                }

                // Push the result back onto the stack
                s.push(op);
            } else {
                // If the token is an operand, convert it to an integer and push onto the stack
                s.push(stoi(x));
            }
        }

        // The final result is on the top of the stack
        return s.top();
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/