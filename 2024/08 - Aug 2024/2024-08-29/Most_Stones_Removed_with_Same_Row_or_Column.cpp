class Solution {
public:
    void dfs(int &n, int idx, vector<bool>& visited, vector<vector<int>>& stones) {
        // Mark the current stone as visited
        visited[idx] = true;

        // Iterate through all other stones
        for (int i = 0; i < n; i++) {
            // If the stone is not visited and has the same row or column as the current stone
            if (!visited[i] && (stones[idx][0] == stones[i][0] || stones[idx][1] == stones[i][1])) {
                // Recursively explore the connected stone
                dfs(n, i, visited, stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int group = 0; // Count the number of connected groups

        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            // If the stone is not visited, it belongs to a new group
            if (!visited[i]) {
                dfs(n, i, visited, stones);
                group += 1; // Increment the group count
            }
        }

        // The number of stones to remove is equal to the total number of stones minus the number of groups
        return n - group;
    }
};
// Time Complexity: O(m * n)
// Space Complexity: O(n)
