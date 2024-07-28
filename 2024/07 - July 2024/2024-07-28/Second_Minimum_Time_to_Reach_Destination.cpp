class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Create the graph using an unordered_map of lists
        unordered_map<int, list<int>> g;
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});  // (time, node)

        vector<int> uniqueVisit(n + 1, 0);  // To track the number of unique visits
        vector<int> dis(n + 1, -1);  // To store the minimum time to reach each node

        while (!q.empty()) {
            auto [t, node] = q.top();
            q.pop();  // Get the node with the smallest time

            // If the node has been visited twice or has the same time as before, skip it
            if (dis[node] == t || uniqueVisit[node] >= 2) {
                continue;
            }

            uniqueVisit[node]++;
            dis[node] = t;

            // If we reached the destination and it's the second visit, return the time
            if (node == n && uniqueVisit[node] == 2) {
                return dis[node];
            }

            // Calculate the leaving time (waiting for the green light)
            if ((t / change) % 2 != 0) {
                t = (t / change + 1) * change;
            }

            // Explore all adjacent nodes
            for (int nei : g[node]) {
                q.push({t + time, nei});
            }
        }

        return -1;  // If there's no second minimum time
    }
};
// Time Complexity: O((V + E) * log(V))
// Space Complexity: O(V + E)