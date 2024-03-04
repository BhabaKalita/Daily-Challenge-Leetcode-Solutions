#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // Initialize variables
        int maxCount = 0, score = 0, n = tokens.size();

        // Two pointers to keep track of tokens from both ends
        int i = 0, j = n - 1;

        // Sort tokens in ascending order
        sort(begin(tokens), end(tokens));

        // Loop until both pointers meet
        while (i <= j) {
            // If we have enough power to buy token at i
            if (power >= tokens[i]) {
                // Buy token, increment score, update maxCount
                power -= tokens[i];
                score++, i++;
                maxCount = max(maxCount, score);
            }
            // If we have at least one token to trade for power
            else if (score >= 1) {
                // Trade token for power, decrement score
                score--;
                power += tokens[j];
                j--;
            }
            // If we can't buy any more tokens and can't trade for power
            else {
                // Return the maximum score obtained so far
                return maxCount;
            }
        }
        // Return the maximum score obtained
        return maxCount;    
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(1)
*/