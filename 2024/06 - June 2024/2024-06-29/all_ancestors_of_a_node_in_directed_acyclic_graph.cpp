class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Resultant 2D vector to store ancestors for each node
        vector<vector<int>> res(n);
        // Adjacency list representation of the graph
        vector<vector<int>> graph(n);

        // Build the graph from the edges
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        // Perform DFS for each node to find all ancestors
        for (int i = 0; i < n; ++i) {
            // Track visited nodes during DFS
            vector<bool> visit(n, false);
            // Start DFS from node 'i' to find its descendants and mark 'i' as their ancestor
            dfs(graph, i, i, res, visit);
        }

        // Sort the ancestors for each node to meet the problem requirements
        for (int i = 0; i < n; ++i) {
            sort(res[i].begin(), res[i].end());
        }

        return res;
    }

private:
    void dfs(vector<vector<int>>& graph, int parent, int curr, vector<vector<int>>& res, vector<bool>& visit) {
        // Mark the current node as visited
        visit[curr] = true;
        // Traverse all the descendants of the current node
        for (int dest : graph[curr]) {
            // If the descendant node has not been visited
            if (!visit[dest]) {
                // Add the ancestor 'parent' to the descendant 'dest'
                res[dest].push_back(parent);
                // Recursive DFS call for the descendant
                dfs(graph, parent, dest, res, visit);
            }
        }
    }
};
// Time Complexity: O(E+V(V+E)+V2logV)
// Space Complexity: O(V2+V+E)