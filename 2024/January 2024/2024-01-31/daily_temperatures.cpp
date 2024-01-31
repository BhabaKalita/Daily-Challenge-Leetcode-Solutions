#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Initialize a vector to store the result with default values of 0
        vector<int> result(temperatures.size(), 0);
        // Stack to store the indices of temperatures for which we need to find the next warmer temperature
        vector<int> stack;

        // Traverse the temperatures in reverse order
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            int currTemperature = temperatures[i];

            // Pop elements from the stack until the stack is empty or the current temperature is greater
            // This ensures that we have the indices of temperatures waiting for the next warmer temperature
            while (!stack.empty() && currTemperature >= temperatures[stack.back()]) {
                stack.pop_back();
            }

            // If the stack is not empty, calculate the difference between the current index and the index
            // of the next warmer temperature and store it in the result vector
            if (!stack.empty()) {
                result[i] = stack.back() - i;
            }

            // Push the current index onto the stack, as it might be the next warmer temperature for
            // temperatures encountered later in the traversal
            stack.push_back(i);
        }

        // Return the result vector containing the number of days until the next warmer temperature for each day
        return result;
    }
};

