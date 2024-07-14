class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stk;
        stk.push({}); // Initialize with an empty map to hold the current scope

        int i = 0, n = formula.length();

        while (i < n) {
            if (formula[i] == '(') {
                // When encountering '(', push a new empty map to the stack
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                // When encountering ')', pop the top map and apply multiplier
                unordered_map<string, int> top = stk.top();
                stk.pop();
                i++;
                int start = i;
                // Read the multiplier after ')'
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int multiplier = start < i ? stoi(formula.substr(start, i - start)) : 1;
                // Multiply each element in the popped map by the multiplier and add to the map below
                for (auto& kv : top) {
                    stk.top()[kv.first] += kv.second * multiplier;
                }
            } else {
                // Reading an element
                int start = i++;
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string element = formula.substr(start, i - start);
                start = i;
                // Read the number of atoms for the element
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int count = start < i ? stoi(formula.substr(start, i - start)) : 1;
                // Add the element and its count to the current map
                stk.top()[element] += count;
            }
        }

        // Collect results from the final map
        unordered_map<string, int> result = stk.top();
        vector<string> elements;
        for (auto& kv : result) {
            elements.push_back(kv.first);
        }
        sort(elements.begin(), elements.end());

        // Build the final result string
        string res;
        for (const auto& element : elements) {
            res += element;
            if (result[element] > 1) {
                res += to_string(result[element]);
            }
        }

        return res;
    }
};
// Time Complexity: O(n+klogk)
// Space Complexity: O(n+k)