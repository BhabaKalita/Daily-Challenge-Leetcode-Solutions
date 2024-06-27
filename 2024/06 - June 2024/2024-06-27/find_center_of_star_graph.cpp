class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> edge;  // Create a map to count the occurrence of each vertex.

        for(auto x:edges) {  // Iterate over each edge in the edges list.
            int u = x[0];  // Extract the first vertex of the edge.
            int v = x[1];  // Extract the second vertex of the edge.

            edge[u]++;  // Increment the count for the first vertex.
            edge[v]++;  // Increment the count for the second vertex.
        }

        for(auto y:edge) {  // Iterate over the map to find the vertex with maximum occurrences.
            if(y.second == edges.size())  // Check if the count of the vertex is equal to the number of edges.
                return y.first;  // If true, this vertex is the center of the star graph.
        }

        return -1;  // If no center is found, return -1 (though this should not happen for a valid star graph).
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)