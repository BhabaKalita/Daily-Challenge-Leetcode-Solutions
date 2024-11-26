class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // Create an array to track the indegree (number of incoming edges) for each node.
        vector<int> indegree(n, 0);

        // Iterate through the edges to calculate the indegree for each node.
        for(auto edge : edges) {
            int u = edge[0]; // Start node of the edge
            int v = edge[1]; // End node of the edge

            indegree[v]++; // Increment the indegree of the end node
        }

        int champ = -1; // To store the node with indegree 0
        int count = 0;  // Counter to ensure there's exactly one node with indegree 0

        // Iterate through all nodes to find the potential champion
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) { // Node with no incoming edges
                champ = i;         // Set this node as the current champion
                count++;           // Increment the count of nodes with indegree 0

                // If more than one node has indegree 0, there is no unique champion
                if(count > 1) 
                    return -1;
            }
        }

        // If exactly one node has indegree 0, return it as the champion.
        // Otherwise, return -1 (no champion or multiple champions).
        return champ;
    }
};
/*
Time Complexity: O(E+n)O(E+n), where EE is the number of edges and nn is the number of nodes.
Space Complexity: O(n)
*/
