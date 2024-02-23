#include <vector>
#include <algorithm> // for min

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Initialize a vector to store the minimum cost to reach each node.
        vector<int> c(n, 1e8); // Initialize all costs to a large value (infinite).

        // The cost to reach the source node is 0.
        c[src] = 0;

        // Iterate for k+1 times as we are allowed to make k stops.
        for(int i = 0; i <= k; i++) {
            // Create a temporary vector to store updated costs.
            vector<int> temp(c);

            // Iterate over each flight.
            for(auto x : flights) {
                // Update the cost to reach the destination node of the flight if it reduces the cost.
                temp[x[1]] = min(temp[x[1]], c[x[0]] + x[2]);
            }

            // Update the main cost vector with the temporary one.
            c = temp;
        }

        // Return the final cost to reach the destination node.
        return c[dst] == 1e8 ? -1 : c[dst];
    }
};

/*
Time Complexity: O((k+1) * m)
Space Complexity: O(n+m)
*/