class Solution {
public:
    bool isNStraightHand(vector<int> hand, int W) {
        // Map to count occurrences of each card
        map<int, int> c;

        // Count each card in the hand
        for (int i : hand) {
            c[i]++;
        }

        // Iterate over each unique card in the map
        for (auto it : c) {
            // If there are any cards of this value left
            if (c[it.first] > 0) {
                // Try to form a group of W consecutive cards
                for (int i = W - 1; i >= 0; --i) {
                    // Decrease the count of each card in the group
                    // If there are not enough cards to form the group, return false
                    if ((c[it.first + i] -= c[it.first]) < 0) {
                        return false;
                    }
                }
            }
        }

        // If all groups are successfully formed, return true
        return true;
    }
};

/*
Time Complexity: O(n log k + k * W)
Space Complexity: O(n + k)
*/