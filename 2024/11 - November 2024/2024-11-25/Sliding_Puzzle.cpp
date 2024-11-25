class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Convert the 2x3 board into a single string for easier manipulation
        string start = "";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }

        // The target string representing the solved puzzle
        string target = "123450";

        // BFS queue to explore all possible board states
        queue<string> que;
        que.push(start);

        // Map representing the valid adjacent positions for each index of '0'
        // For example, index 0 can swap with indices 1 and 3
        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        // Set to keep track of visited states and prevent revisiting
        unordered_set<string> visited;
        visited.insert(start);

        int level = 0; // Represents the number of moves (BFS level)

        // Start BFS
        while(!que.empty()) {
            int n = que.size(); // Number of states at the current level

            // Process all states at the current level
            while(n--) {
                string curr = que.front(); // Current state
                que.pop();

                // If we reach the target configuration, return the level (moves)
                if(curr == target) {
                    return level;
                }

                // Find the index of '0' (empty slot)
                int indexOfZero = curr.find('0');

                // Try swapping '0' with all valid adjacent positions
                for(int swapIdx : mp[indexOfZero]) {
                    string newState = curr;
                    swap(newState[indexOfZero], newState[swapIdx]); // Perform the swap

                    // If this new state hasn't been visited, add it to the queue
                    if(visited.find(newState) == visited.end()) {
                        que.push(newState);
                        visited.insert(newState);
                    }
                }
            }

            // Increment the level after processing all states at the current level
            level++;
        }

        // If we exhaust all possibilities and don't find the target, return -1
        return -1;
    }
};
// Time Complexity: O(6!)=O(720)
// Space Complexity: O(6!)=O(720)
