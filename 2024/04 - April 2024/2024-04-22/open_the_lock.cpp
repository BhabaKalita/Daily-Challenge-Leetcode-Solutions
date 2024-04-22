class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Convert deadends vector to an unordered_set for faster lookup
        unordered_set<string> deadSet(deadends.begin(), deadends.end());

        // If "0000" is one of the deadends, the target cannot be reached
        if (deadSet.count("0000")) return -1;

        // Initialize a queue with the starting combination "0000"
        queue<string> q({"0000"});

        // Perform BFS
        for (int steps = 0; !q.empty(); ++steps) {
            // Process all combinations at current step level
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front(); q.pop();
                // If the current combination is the target, return the steps
                if (curr == target) return steps;
                // Generate neighbors of the current combination and add them to the queue
                for (auto nei : neighbors(curr)) {
                    // Skip if the neighbor is in the deadends
                    if (deadSet.count(nei)) continue;
                    // Mark the neighbor as visited and add it to the queue
                    deadSet.insert(nei);
                    q.push(nei);
                }
            }
        }

        // If the target cannot be reached, return -1
        return -1;
    }

    // Function to generate all possible neighbors of a combination
    vector<string> neighbors(const string& code) {
        vector<string> result;
        // Loop through each digit of the combination
        for (int i = 0; i < 4; i++) {
            // Loop through possible changes for each digit (+1 and -1)
            for (int diff = -1; diff <= 1; diff += 2) {
                // Create a new combination by changing one digit
                string nei = code;
                nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
                // Add the new combination to the result
                result.push_back(nei);
            }
        }
        return result;
    }
};

/*
Time Complexity: O(N * D), where N is the total number of possible combinations (10^4 = 10000) and D is the size of the deadends vector. In the worst case, we might visit all possible combinations.
Space Complexity: O(N + D), where N is the space required for the queue and the set of visited combinations, and D is the size of the deadends vector.
*/