class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Define the UnionFind class to manage union-find operations
        class UnionFind {
        public:
            vector<int> parent, size;
            int components;

            // Constructor initializes the union-find structure
            UnionFind(int n) {
                components = n;
                parent.resize(n + 1);
                size.resize(n + 1, 1);
                for (int i = 0; i <= n; ++i) {
                    parent[i] = i;
                }
            }

            // Find function with path compression
            int find(int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            }

            // Union function with union by size
            bool unite(int x, int y) {
                int rootX = find(x), rootY = find(y);
                if (rootX == rootY) return false;
                if (size[rootX] < size[rootY]) swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                components--;
                return true;
            }

            // Check if the structure is fully connected
            bool isConnected() {
                return components == 1;
            }
        };

        UnionFind alice(n), bob(n);
        int edgesRequired = 0;

        // Process type 3 edges first (shared by both Alice and Bob)
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }

        // Process type 1 edges (Alice's edges) and type 2 edges (Bob's edges)
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (alice.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            } else if (edge[0] == 2) {
                if (bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }

        // Check if both Alice and Bob's graphs are fully connected
        if (alice.isConnected() && bob.isConnected()) {
            return edges.size() - edgesRequired;  // Return the number of removable edges
        }

        return -1;  // Return -1 if either graph is not fully connected
    }
};
// Time Complexity: O(E + N)
// Space Complexity: O(N)