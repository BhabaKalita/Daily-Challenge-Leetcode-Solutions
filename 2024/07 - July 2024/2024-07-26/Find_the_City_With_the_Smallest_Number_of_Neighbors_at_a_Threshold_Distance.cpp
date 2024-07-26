public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize distance matrix with infinity (a large number, here 1000000000)
        vector<vector<int>> distance(n, vector<int>(n, 1000000000)); 

        // Distance to itself is 0 for all cities
        for (int i = 0; i < n; ++i) {
            distance[i][i] = 0;
        }

        // Set the distance for each edge in the graph
        for (auto& edge : edges) {
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }

        // Floyd-Warshall algorithm to find the shortest path between all pairs of nodes
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }

        int ans = -1;  // Variable to store the result city
        int mini = INT_MAX;  // Variable to store the minimum number of reachable cities

        // Find the city with the minimum number of reachable cities within the distanceThreshold
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && distance[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            // Update the result city if the current city has fewer or equal reachable cities
            if (count <= mini) {
                mini = count;
                ans = i;
            }
        }

        return ans;  // Return the result city
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)