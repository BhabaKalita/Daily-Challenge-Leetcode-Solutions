class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // Map to store the count of losses for each player
        unordered_map<int, int> lost_map;

        // Count the losses for each player
        for (int i = 0; i < matches.size(); i++) {
            int loser = matches[i][1];
            lost_map[loser]++;
        }

        // Vectors to store players with no losses and players with one loss
        vector<int> one_loss, no_loss;

        // Check winners and losers in each match
        for (int j = 0; j < matches.size(); j++) {
            int winner = matches[j][0];
            int loser = matches[j][1];

            // If the winner has no losses, add to no_loss vector
            if (lost_map.find(winner) == lost_map.end()) {
                no_loss.push_back(winner);
                lost_map[winner] = 2; // Mark as having 2 losses (to avoid duplicate entries)
            }

            // If the loser has one loss, add to one_loss vector
            if (lost_map[loser] == 1) {
                one_loss.push_back(loser);
            }
        }

        // Sort the vectors
        sort(one_loss.begin(), one_loss.end());
        sort(no_loss.begin(), no_loss.end());

        // Return the result as a vector of vectors
        return {no_loss, one_loss};
    }
};

/*
Time Complexity: O(N + M log M)
Space Complexity: O(N+M)
*/