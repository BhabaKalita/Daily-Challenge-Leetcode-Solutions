class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        // Get the number of rows (m) and columns (n) in the grid
        int m = grid.size(), n = grid[0].size();

        // If the initial grid has more than one island, return 0 (no need to remove any land)
        if(countIsland(grid) != 1) return 0;

        // Try removing each land cell (value 1) one by one
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    // Temporarily remove the land cell
                    grid[i][j] = 0;

                    // If after removal, the grid does not contain exactly one island, return 1
                    if(countIsland(grid) != 1) return 1;

                    // Restore the land cell
                    grid[i][j] = 1;
                }
            }
        }
        // If removing one land cell doesn't split the island, return 2 (at least two removals are needed)
        return 2;
    }

    int countIsland(vector<vector<int>> &grid) {
        // Get the number of rows (m) and columns (n) in the grid
        int m = grid.size();
        int n = grid[0].size();

        // Create a visited matrix to keep track of visited cells
        vector<vector<int>> vis(m, vector<int>(n, false));

        int cnt = 0; // To count the number of islands

        // Iterate through every cell in the grid
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // If the cell is land (1) and not visited, it's part of a new island
                if(grid[i][j] == 1 && !vis[i][j]) {
                    cnt++; // Increment the island count
                    // Perform a Depth-First Search (DFS) to mark all cells of this island as visited
                    dfs(grid, i, j, vis);
                }
            }
        }
        return cnt; // Return the number of islands
    }

    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &vis) {
        int m = grid.size(), n = grid[0].size();

        // Boundary checks and if the cell is water (0) or already visited, return
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || vis[i][j] == true)
            return;

        // Mark the current cell as visited
        vis[i][j] = true;

        // Recursively visit all neighboring cells (up, down, left, right)
        dfs(grid, i + 1, j, vis);
        dfs(grid, i - 1, j, vis);
        dfs(grid, i, j + 1, vis);
        dfs(grid, i, j - 1, vis);
    }
};
// Time Complexity: O(m^2 * n^2)
// Space Complexity: O(m*n)