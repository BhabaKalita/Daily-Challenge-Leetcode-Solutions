class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Create a graph for row conditions
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : rowConditions) {
            graph[edge[0]].push_back(edge[1]);
        }

        // Get topological sorting for row conditions
        vector<int> row_sorting = topo_sort(graph, k);

        // Clear the graph and rebuild it for column conditions
        graph.clear();
        for (const auto& edge : colConditions) {
            graph[edge[0]].push_back(edge[1]);
        }

        // Get topological sorting for column conditions
        vector<int> col_sorting = topo_sort(graph, k);

        // If either sorting is empty, a cycle was detected
        if (row_sorting.empty() || col_sorting.empty()) {
            return {};
        }

        // Map values to their row and column positions
        unordered_map<int, pair<int, int>> value_position;
        for (int i = 0; i < k; ++i) {
            value_position[row_sorting[i]].first = i;
            value_position[col_sorting[i]].second = i;
        }

        // Build the result matrix
        vector<vector<int>> res(k, vector<int>(k, 0));
        for (int value = 1; value <= k; ++value) {
            int row = value_position[value].first;
            int column = value_position[value].second;
            res[row][column] = value;
        }

        return res;
    }

private:
    // Depth-first search function to detect cycles and perform topological sort
    bool dfs(int src, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, unordered_set<int>& cur_path, vector<int>& res) {
        if (cur_path.count(src)) return false;  // cycle detected
        if (visited.count(src)) return true;  // already visited this node

        visited.insert(src);
        cur_path.insert(src);

        // Visit all neighbors
        for (int neighbor : graph[src]) {
            if (!dfs(neighbor, graph, visited, cur_path, res))  // if any child returns false
                return false;
        }

        cur_path.erase(src);  // backtrack path
        res.push_back(src);
        return true;
    }

    // Topological sort function
    vector<int> topo_sort(unordered_map<int, vector<int>>& graph, int k) {
        unordered_set<int> visited;
        unordered_set<int> cur_path;
        vector<int> res;

        // Try to visit each node from 1 to k
        for (int src = 1; src <= k; ++src) {
            if (!dfs(src, graph, visited, cur_path, res))
                return {};
        }

        // Reverse the result to get the correct order
        reverse(res.begin(), res.end());
        return res;
    }
};
// Time Complexity: O(V+E)
// Space Complexity: O(k^2)