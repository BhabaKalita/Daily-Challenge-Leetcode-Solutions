#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Create an adjacency list to represent the graph
        unordered_map<int, vector<int>> adj;

        // Populate the adjacency list
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]); // Since the graph is undirected
        }

        // Queue for BFS traversal
        queue<int> q;

        // Map to mark visited nodes
        unordered_map<int, int> vis;

        // Start BFS from source node
        q.push(source);
        vis[source] = 1;

        // Perform BFS traversal
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            // If the current node is the destination, return true
            if(cur == destination)
                return true;

            // Explore neighbors of the current node
            for(auto y : adj[cur]) {
                // If the neighbor is not visited, add it to the queue and mark as visited
                if(!vis[y]) {
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }

        // If destination is not reached, return false
        return false;
    }
};

/*
Time Comlexity: O(V+E)
Space Comlexity: O(V+E)
*/