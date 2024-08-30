class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // Create an adjacency list representation of the graph
        vector<vector<pair<int, int>>> adjacencyList(n);
        for (int i = 0; i < edges.size(); i++) {
            int nodeA = edges[i][0], nodeB = edges[i][1];
            adjacencyList[nodeA].emplace_back(nodeB, i); // Add edge (nodeA, nodeB) with index i to adjacency list
            adjacencyList[nodeB].emplace_back(nodeA, i); // Add the reverse edge for undirected graph
        }

        // Initialize distances for two Dijkstra runs (source to destination with original weights, source to destination with modified weights)
        vector<vector<int>> distances(n, vector<int>(2, INT_MAX));
        distances[source][0] = distances[source][1] = 0;

        // Run Dijkstra's algorithm twice for each distance calculation
        runDijkstra(adjacencyList, edges, distances, source, 0, 0); // Find shortest path with original weights (run 0)
        int difference = target - distances[destination][0]; // Calculate the difference between target and shortest path length
        if (difference < 0) return {}; // No solution possible if target is less than shortest path

        runDijkstra(adjacencyList, edges, distances, source, difference, 1); // Find shortest path with modified weights (run 1)
        if (distances[destination][1] < target) return {}; // No solution possible if modified shortest path is still less than target

        // Modify edge weights in the original edge list based on the second Dijkstra run
        for (auto& edge : edges) {
            if (edge[2] == -1) edge[2] = 1; // Set default weight to 1 if not specified
        }

        return edges;
    }

private:
    void runDijkstra(const vector<vector<pair<int, int>>>& adjacencyList, vector<vector<int>>& edges, vector<vector<int>>& distances, int source, int difference, int run) {
        int n = adjacencyList.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, source});
        distances[source][run] = 0;

        while (!priorityQueue.empty()) {
            auto [currentDistance, currentNode] = priorityQueue.top();
            priorityQueue.pop();

            if (currentDistance > distances[currentNode][run]) continue; // Skip already relaxed nodes

            for (auto& neighbor : adjacencyList[currentNode]) {
                int nextNode = neighbor.first, edgeIndex = neighbor.second;
                int weight = edges[edgeIndex][2];

                if (weight == -1) weight = 1; // Set default weight to 1 if not specified

                // Modify weight for the second Dijkstra run based on the difference
                if (run == 1 && edges[edgeIndex][2] == -1) {
                    int newWeight = difference + distances[nextNode][0] - distances[currentNode][1];
                    weight = max(weight, newWeight); // Update weight to the larger value (original or modified)
                }

                if (distances[nextNode][run] > distances[currentNode][run] + weight) {
                    distances[nextNode][run] = distances[currentNode][run] + weight;
                    priorityQueue.push({distances[nextNode][run], nextNode});
                }
            }
        }
    }
};
// Time Complexity: O(n * log n * m)
// Space Complexity: O(n + m)
