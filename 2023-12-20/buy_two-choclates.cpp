#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // Initialize two variables to track the lowest and second lowest prices
        int first = INT_MAX, second = first;

        // Iterate through the prices vector to find the two lowest prices
        for (int i = 0; i < prices.size(); i++) {
            // If the current price is lower than the lowest recorded price
            if (prices[i] < first) {
                // Update both the lowest and second lowest prices
                second = first;
                first = prices[i];
            } 
            // If the current price is higher than the lowest but lower than the second lowest
            else if (prices[i] < second) {
                // Update only the second lowest price
                second = prices[i];
            }
        }

        // Calculate the total cost of buying the two lowest priced chocolates
        int total = first + second;

        // Determine the remaining money after buying chocolates
        // If the total cost is less than or equal to the available money, return the difference
        // Otherwise, return the original money (no chocolates can be bought)
        return (total <= money) ? money - total : money;
    }
};


/*
Time Complexity: O(N)
Space Complexity: O(1)
*/