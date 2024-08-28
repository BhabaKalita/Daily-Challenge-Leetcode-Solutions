class Solution {
public:
    int n, m;
    bool flag;
    bool vst[505][505];
    vector<vector<int>> grid_i, grid_ii;

    void dfs(int i, int j) {
        // Base cases:
        if (i < 0 || j < 0 || i >= n || j >= m || !grid_ii[i][j] || vst[i][j]) {
            return;
        }

        // Mark the current cell as visited
        vst[i][j] = true;

        // Check if the current cell in grid1 is 0
        if (!grid_i[i][j]) {
            flag = false; // Set the flag to false if a 0 is found
        }

        // Recursively explore neighboring cells
        dfs(i + 1, j);
        dfs(i, j + 1);
        dfs(i - 1, j);
        dfs(i, j - 1);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        grid_i = grid1, grid_ii = grid2;
        n = grid1.size(), m = grid1[0].size();

        // Iterate through each cell in grid2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is not visited and is 1 in grid2
                if (!vst[i][j] && grid_ii[i][j]) {
                    flag = true; // Initialize the flag to true
                    dfs(i, j); // Perform DFS to explore the island
                    ans += flag; // Increment the answer if the island is a sub-island
                }
            }
        }

        return ans;
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
