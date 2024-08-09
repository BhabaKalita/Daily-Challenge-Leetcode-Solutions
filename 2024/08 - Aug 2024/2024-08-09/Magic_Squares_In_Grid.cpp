class Solution {
public:
    // Function to count the number of 3x3 magic squares in the grid
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;

        // Iterate over each cell in the grid
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                // If the 3x3 grid starting at (i, j) is a magic square, increment the result
                if(isMagicSquare(grid, i, j))
                    res++;
            }
        }

        return res; // Return the total count of magic squares
    }

    // Helper function to check if the 3x3 grid starting at (r, c) is a magic square
    bool isMagicSquare(vector<vector<int>> &grid, int r, int c) {

        // Ensure the 3x3 grid starting at (r, c) is within the bounds of the main grid
        if(r+2 < grid.size() && c+2 < grid[0].size()) {

            // Calculate the sum of columns, rows, and diagonals in the 3x3 grid
            int col1 = grid[r][c] + grid[r+1][c] + grid[r+2][c];
            int col2 = grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1];
            int col3 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2];
            int row1 = grid[r][c] + grid[r][c+1] + grid[r][c+2];
            int row2 = grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2];
            int row3 = grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2];
            int diag1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
            int diag2 = grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2];

            // Check if all sums are equal
            if(col1 == col2 && col1 == col3 && col1 == row1 && col1 == row2 && col1 == row3 && col1 == diag1 && col1 == diag2) {
                // Check if the 3x3 grid contains exactly the numbers 1 to 9
                set<int> s = {1,2,3,4,5,6,7,8,9};

                for(int i=0; i<3; i++) {
                    for(int j=0; j<3; j++) {
                        s.erase(grid[i+r][j+c]); // Remove the numbers found in the 3x3 grid from the set
                    }
                }

                // If the set is empty, the grid is a magic square
                return s.empty();
            }
        }
        return false; // Return false if it's not a magic square
    }
};
// Time Complexity: O(n×m)
// Space Complexity: O(1)