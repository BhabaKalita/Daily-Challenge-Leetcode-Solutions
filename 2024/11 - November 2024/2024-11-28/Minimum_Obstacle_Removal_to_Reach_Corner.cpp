class Solution {
public:
    // Define a pair for use in the priority queue: {weight, {row, col}}
    #define P pair<int, pair<int, int>>

    // Directions for moving up, down, left, and right in the grid
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns

        // Result matrix to store the minimum obstacles encountered to reach each cell
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = 0; // Starting point has 0 obstacles encountered

        // Min-heap to store the cells based on the cost to reach them
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}}); // Start with the top-left corner (0,0) with cost 0

        // Process the grid using Dijkstra's algorithm
        while(!pq.empty()) {
            auto curr = pq.top(); // Get the cell with the minimum cost
            pq.pop();

            int d = curr.first;           // Current cost
            int i = curr.second.first;    // Current row
            int j = curr.second.second;   // Current column

            // Explore all four possible directions
            for(auto &dir : directions) {
                int x = i + dir[0];       // New row
                int y = j + dir[1];       // New column

                // Check if the new cell is out of bounds
                if(x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                // Weight to move to the new cell: 1 if it's an obstacle, 0 otherwise
                int wt = (grid[x][y] == 1) ? 1 : 0;

                // Update the result if a smaller cost is found for this cell
                if(d + wt < result[x][y]) {
                    result[x][y] = d + wt;    // Update the cost for the cell
                    pq.push({d + wt, {x, y}}); // Push the cell into the priority queue
                }
            }
        }

        // Return the minimum cost to reach the bottom-right corner
        return result[m-1][n-1];
    }
};
// Time Complexity : O((m×n)⋅log(m×n))
// Space Complexity : O(m×n)
