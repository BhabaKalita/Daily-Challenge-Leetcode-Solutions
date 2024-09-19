class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // Create a vector to store the results.
        vector<int> res;

        // Iterate over each character in the expression.
        for (int i = 0; i < expression.size(); i++) {
            char oper = expression[i];

            // If the character is an operator (+, -, *),
            // recursively compute the results for the left and right sub-expressions.
            if (oper == '+' || oper == '-' || oper == '*') {
                vector<int> s1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i + 1));

                // Combine the results from the left and right sub-expressions using the operator.
                for (auto a : s1) {
                    for (auto b : s2) {
                        if (oper == '+') {
                            res.push_back(a + b);
                        } else if (oper == '-') {
                            res.push_back(a - b);
                        } else if (oper == '*') {
                            res.push_back(a * b);
                        }
                    }
                }
            }
        }

        // If no operator was found, the expression is a single number.
        if (res.empty()) {
            res.push_back(stoi(expression));
        }

        // Return the vector of results.
        return res;
    }
};
/*
  Time Complexity : O(2^n)
  Space Complexity : O(2^n)
*/
