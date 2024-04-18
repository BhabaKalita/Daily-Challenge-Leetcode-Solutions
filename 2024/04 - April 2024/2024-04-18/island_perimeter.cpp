class Solution {
public:
    int count = 0; // Variable to store the perimeter count

    // Function to calculate the perimeter of the islands
    int islandPerimeter(vector<vector<int>>& grid) {
        // Loop through each cell of the grid
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                // If the cell is part of an island
                if(grid[i][j] == 1) {
                    // Start DFS from this cell
                    dfs(grid, i, j);
                    // Break once we've found the first island
                    break;
                }
            }
        }
        // Return the perimeter count
        return count;
    }

    // Depth-first search to explore the island
    void dfs(vector<vector<int>>& grid, int i, int j) {
        // If we're out of bounds or reached water, increment count and return
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            count++;
            return;
        }

        // If we've already visited this cell, return
        if(grid[i][j] == -1) return;

        // Mark the cell as visited
        grid[i][j] = -1;

        // Explore all four directions
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

/*
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/