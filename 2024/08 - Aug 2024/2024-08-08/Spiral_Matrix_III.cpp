class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // Define directions: right, down, left, and up
        vector<vector<int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int dir = 0;  // Start with direction 'right'
        int step = 0; // Number of steps to take in the current direction
        vector<vector<int>> res; // Resultant vector to store the spiral order cells

        // Start with the initial position
        res.push_back({rStart, cStart});

        // Continue until we've covered all cells in the grid
        while (res.size() < rows * cols) {

            // Increase step count after moving in 'right' or 'left' direction
            if (dir == 0 || dir == 2) step++;

            // Move 'step' times in the current direction
            for (int i = 0; i < step; i++) {
                // Update the current position
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                // If the new position is within bounds, add it to the result
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    res.push_back({rStart, cStart});
            }

            // Change direction (right -> down -> left -> up -> right -> ...)
            dir = (dir + 1) % 4;
        }

        return res; // Return the spiral order of cells
    }
};
// Time Complexity: O(rows * cols)
// Space Complexity: O(N)