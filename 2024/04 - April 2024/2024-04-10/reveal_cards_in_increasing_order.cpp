#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Sort the deck in descending order
        sort(deck.rbegin(), deck.rend());

        // Create a deque to simulate the process of revealing cards
        deque<int> d;

        // Push the largest card from the sorted deck to the front of the deque
        d.push_front(deck[0]);

        // Iterate through the remaining cards
        for(int i = 1; i < deck.size(); i++) {
            // Move the last card in the deque to the front
            d.push_front(d.back());
            // Remove the last card from the deque
            d.pop_back();
            // Push the current card from the sorted deck to the front of the deque
            d.push_front(deck[i]);
        }

        // Convert the deque to a vector
        vector<int> res(d.begin(), d.end());

        // Return the resulting vector containing the ordered deck
        return res;
    }
};

// Time Complexity:
// Sorting the deck: O(n log n)
// Iterating through the deck: O(n)
// Overall time complexity: O(n log n)

// Space Complexity:
// Deque size: O(n)
// Vector size: O(n)
// Overall space complexity: O(n)
