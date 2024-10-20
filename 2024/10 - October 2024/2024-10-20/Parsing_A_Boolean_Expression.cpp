class Solution {
public:
    bool parseBoolExpr(string expression) {
        // 1. Create a stack to store operands and operators
        stack<char> st;

        // 2. Iterate through each character in the expression
        for (auto curr : expression) {
            // 3. Ignore commas and opening parentheses (not used for evaluation)
            if (curr == ',' || curr == '(') continue;

            // 4. Push operators (including '!', '&', '|') and operands ('t' or 'f') onto the stack
            else if (curr == '!' || curr == '&' || curr == '|' || curr == 't' || curr == 'f') {
                st.push(curr);
            }

            // 5. Handle closing parenthesis ')'
            else if (curr == ')') {
                // 5.1 Initialize flags to track encountered 't' and 'f' values
                bool hasTrue = false, hasFalse = false;

                // 5.2 Process elements until encountering a valid operator ('!', '&', or '|')
                while (!st.empty() && st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char topVal = st.top();
                    st.pop();

                    // 5.3 Update flags based on encountered operands
                    if (topVal == 'f') {
                        hasFalse = true;
                    } else if (topVal == 't') {
                        hasTrue = true;
                    }
                }

                // 5.4 Extract the operator from the stack
                char op = st.top();
                st.pop();

                // 5.5 Evaluate the expression based on the operator and encountered flags
                if (op == '!') {
                    // Not operator: push 'f' if 't' was encountered, 't' otherwise
                    st.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    // And operator: push 'f' if 'f' was encountered, 't' otherwise
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    // Or operator: push 't' if 't' was encountered, 'f' otherwise
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }

        // 6. The final element on the stack should be the result ('t' or 'f')
        return st.top() == 't';
    }
};

// Time Complexity: O(n)

// Space Complexity: O(n)
