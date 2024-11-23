class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // Get the number of rows (ROWS) and columns (COLS) in the input box matrix.
        int ROWS = box.size();
        int COLS = box[0].size();
        
        // Create a result matrix 'res' of dimensions COLS x ROWS (rotated dimensions).
        // Initialize all cells with '.' (empty spaces).
        vector<vector<char>> res(COLS, vector<char>(ROWS, '.'));
        
        // Iterate through each row in the box matrix.
        for (int r = 0; r < ROWS; r++) {
            // Set 'i' to the last column index (COLS - 1) for placing stones after gravity.
            int i = COLS - 1;
            
            // Iterate through the current row from right to left (reverse column order).
            for (int c = COLS - 1; c >= 0; c--) {
                // If the current cell contains a stone ('#'):
                if (box[r][c] == '#') {
                    // Place the stone in the rotated position at (i, ROWS - r - 1).
                    res[i][ROWS - r - 1] = '#';
                    // Move 'i' one step left to place the next stone lower in the rotated box.
                    i--;
                }
                // If the current cell contains an obstacle ('*'):
                else if (box[r][c] == '*') {
                    // Place the obstacle in the rotated position at (c, ROWS - r - 1).
                    res[c][ROWS - r - 1] = '*';
                    // Update 'i' to be just before the obstacle since stones can't fall past it.
                    i = c - 1;
                }
                // If the cell is empty ('.'), do nothing because the initial state of 'res' is empty.
            }
        }
        
        // Return the rotated and gravity-adjusted box matrix.
        return res;
    }
};
//Complexy: Time O(m * n) & Space O(m * n)
