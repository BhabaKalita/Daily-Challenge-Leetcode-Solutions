#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // Using a priority queue to store pairs of (score, index)
        priority_queue<pair<int, int>> q;

        // Pushing each score along with its index into the priority queue
        for(int i = 0; i < score.size(); i++)
            q.push({score[i], i});

        // Initializing a vector to store the result
        vector<string> res(score.size());

        // Variable to track the rank
        int rank = 0;

        // Processing the priority queue until it's empty
        while (!q.empty()) {
            // Fetching the index of the current maximum score
            int index = q.top().second;

            // Assigning the rank based on position
            // If it's the first three positions, assign Gold, Silver, or Bronze Medal respectively
            // For positions beyond 3, assign the rank as the position number
            res[index] = rank == 0 ? "Gold Medal" : rank == 1 ? "Silver Medal" : rank == 2 ? "Bronze Medal" : to_string(rank + 1);

            // Incrementing the rank
            rank++;

            // Popping the current maximum score from the priority queue
            q.pop();
        }

        return res;
    }
};
// Time Complexity: O(n log n)
// Space Complexity: O(n)