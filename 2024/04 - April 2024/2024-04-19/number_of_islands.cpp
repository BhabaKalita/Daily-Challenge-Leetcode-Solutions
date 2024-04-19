class Solution {
public:
    int count = 0; // Initialize count of islands

    // Function to count the number of islands
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(); // Number of rows in the grid
        int col = grid[0].size(); // Number of columns in the grid

        // Traverse each cell of the grid
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                // If cell contains '1', perform DFS to mark adjacent cells and count island
                if(grid[i][j] == '1') {
                    dfs(grid, i, j); // Perform Depth First Search from current cell
                    count++; // Increment count of islands
                }
            }
        }
        return count; // Return total count of islands
    }

    // Depth First Search to mark adjacent cells of an island
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Check for out-of-bounds or cell with value '0'
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return; // Return if conditions are met
        }

        if(grid[i][j] == -1) return; // If cell is already visited, return

        grid[i][j] = -1; // Mark current cell as visited

        // Recursively call DFS on adjacent cells
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }
};

/*
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/