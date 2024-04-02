#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // Adjacency list to represent graph
        vector<vector<pair<int, int>>> adj(n);

        // Constructing the adjacency list
        for (auto x : meetings) {
            int u = x[0];
            int v = x[1];
            int t = x[2];

            adj[u].push_back({v, t}); // Add edge from u to v with weight t
            adj[v].push_back({u, t}); // Add edge from v to u with weight t (assuming undirected graph)
        }

        // Min heap to store next meeting time and person
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Array to mark visited persons
        vector<int> vis(n);

        // Push initial state into priority queue
        pq.push({0, 0}); // Start time is 0, starting from person 0
        pq.push({0, firstPerson}); // Start time is 0, starting from given firstPerson

        // Dijkstra's algorithm to find reachable persons
        while (!pq.empty()) {
            auto [t, x] = pq.top(); // Extract next meeting time and person
            pq.pop();

            if (vis[x]) continue; // Skip if person x is already visited
            vis[x] = 1; // Mark person x as visited

            // Traverse through all neighbors of person x
            for (auto &y : adj[x]) {
                if (vis[y.first]) continue; // Skip if neighbor is already visited

                if (y.second >= t) {
                    pq.push({y.second, y.first}); // If meeting time is later or equal to current time, add it to priority queue
                }
            }
        }

        // Collect reachable persons
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i]) ans.push_back(i);
        }

        return ans;
    }
};

/*
Time Complexity: O(ElogV)
Space Complexity: O(E+V)
*/