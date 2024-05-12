class Solution {
public:
    // Function to find the largest local value in each 3x3 subgrid of the input grid
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        // Define a result grid to store the largest local values
        // The result grid has dimensions (n-2) x (n-2)
        vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));

        // Iterate over each subgrid of size 3x3
        for (int row = 0; row < n - 2; row++) {
            for (int col = 0; col < n - 2; col++) {
                int temp = 0;

                // Iterate over each cell in the current subgrid
                for (int x = row; x <= row + 2; x++) {
                    for (int y = col; y <= col + 2; y++) {
                        // Update temp with the maximum value found in the current subgrid
                        temp = max(temp, grid[x][y]);
                    }
                }

                // Store the largest value in the result grid
                res[row][col] = temp;
            }
        }
        // Return the result grid
        return res;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/