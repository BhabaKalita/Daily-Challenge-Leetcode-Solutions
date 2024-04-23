class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& E) {
        // If there are no edges, return a single node as the root
        if (E.empty()) return {0};

        // Create an adjacency list representation of the graph
        vector<vector<int>> G(n);
        for (auto& e : E) {
            // Add edges to the adjacency list
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }

        // Initialize vectors to store leaf nodes and their adjacent nodes
        vector<int> leaves, newLeaves, inDegree;
        // Calculate in-degree for each node and find initial leaf nodes
        for (int i = 0; i < n; i++) {
            if (G[i].size() == 1)
                leaves.push_back(i);  // If a node has only one edge, it is a leaf node
            inDegree.push_back(G[i].size()); // Store the in-degree of each node
        }

        // Main loop to remove leaf nodes iteratively until only 1 or 2 nodes remain
        while (n > 2) {
            // Process each leaf node
            for (auto leaf : leaves) {
                // Iterate over adjacent nodes of the current leaf node
                for (auto adj : G[leaf]) {
                    // Decrement in-degree of adjacent nodes
                    if (--inDegree[adj] == 1) {
                        // If the in-degree becomes 1 after removing the leaf,
                        // add the adjacent node as a new leaf
                        newLeaves.push_back(adj);
                    }
                }
            }
            // Update the number of remaining nodes after removing leaf nodes
            n -= leaves.size();
            // Update the list of leaf nodes for the next iteration
            leaves = move(newLeaves);
        }

        // Return the remaining nodes which are the roots of the minimum height trees
        return leaves;
    }
};
/*
Time Complexity: O(n + m) where n is the number of nodes and m is the number of edges
Space Complexity: O(n + m)
*/