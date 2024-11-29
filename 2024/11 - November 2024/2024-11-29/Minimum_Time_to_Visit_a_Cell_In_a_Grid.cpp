class Solution {
public:
    // Directions for moving up, down, left, and right
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // Define a pair type for priority queue: (time, (row, col))
    #define P pair<int, pair<int, int>>

    int minimumTime(vector<vector<int>>& grid) {
        // Get the dimensions of the grid
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns

        // If the first step is blocked, return -1
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        // Create a 2D array to track visited cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Min-heap to process cells in order of increasing time
        priority_queue<P, vector<P>, greater<P>> pq;

        // Start from the top-left corner with the time specified in grid[0][0]
        pq.push({grid[0][0], {0, 0}});
        
        while (!pq.empty()) {
            // Extract the cell with the smallest time
            int time = pq.top().first;              // Current time
            int row = pq.top().second.first;        // Current row
            int col = pq.top().second.second;       // Current column
            pq.pop();
            
            // If we reach the bottom-right corner, return the time
            if (row == m - 1 && col == n - 1)
                return time;
            
            // Skip processing if the cell is already visited
            if (visited[row][col]) continue;
            visited[row][col] = true; // Mark the cell as visited
            
            // Explore all four possible directions
            for (auto dir : direction) {
                int r = row + dir[0]; // New row
                int c = col + dir[1]; // New column
                
                // Check if the new cell is within bounds and not visited
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
                    continue;
                
                // If we can move to the new cell immediately
                if (grid[r][c] <= time + 1)
                    pq.push({time + 1, {r, c}});
                // If the cell becomes accessible on an even time step
                else if ((grid[r][c] - time) % 2 == 0)
                    pq.push({grid[r][c] + 1, {r, c}});
                // If the cell becomes accessible on an odd time step
                else
                    pq.push({grid[r][c], {r, c}});
            }
        }
        
        // If we exhaust all possibilities and can't reach the destination
        return -1;
    }
};
// Time Complexity : O(m×nlog(m×n))
// Space Complexity : O(m×n)
