class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Create a vector to store the maximum probability of reaching each node from the start node
        vector<double> maxProb(n, 0.0);
        // Initialize the probability of reaching the start node as 1.0
        maxProb[start_node] = 1.0;

        // Iterate n-1 times to relax edges and find the maximum probabilities
        for(int i=0; i<n-1; i++) {
            bool updated = false; // Flag to check if any probabilities were updated in this iteration

            // Iterate through all edges
            for(int j=0; j<edges.size(); j++) {

                // Extract the nodes and probability from the edge
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];

                // Relax the edge from u to v
                if(maxProb[u] * prob > maxProb[v]) {
                    maxProb[v] = maxProb[u] * prob;
                    updated = true; // Set the updated flag to true
                }

                // Relax the edge from v to u (if it's bidirectional)
                if(maxProb[v] * prob > maxProb[u]) {
                    maxProb[u] = maxProb[v] * prob;
                    updated = true;
                }
            }

            // If no probabilities were updated in this iteration, it means the maximum probabilities have converged, so break the loop
            if(!updated) break;
        }

        // Return the maximum probability of reaching the end node
        return maxProb[end_node];
    }
};
// Time Complexity: O(m * n)
// Space Complexity: O(n)
