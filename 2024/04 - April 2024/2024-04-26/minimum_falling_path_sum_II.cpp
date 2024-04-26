class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
    // Initialize first minimum and second minimum to 0
    int fm = 0, sm = 0;
    // Initialize position to -1
    int pos = -1;

    // Loop through each row of the input array
    for (auto i = 0; i < grid.size(); ++i) {
        // Initialize first and second minimum of current row and position to -1
        int fm2 = INT_MAX, sm2 = INT_MAX, pos2 = -1;

        // Loop through each element of the current row
        for (auto j = 0; j < grid[i].size(); ++j) {
            // Determine the minimum value considering the previous minimums
            int mn = j != pos ? fm : sm;
            if (grid[i][j] + mn < fm2) {
                // Update first and second minimums and position if current element contributes to a new minimum
                sm2 = fm2;
                fm2 = grid[i][j] + mn;
                pos2 = j;
            } else {
                // Update second minimum if current element contributes to a new second minimum
                sm2 = min(sm2, grid[i][j] + mn);
            }
        }
        // Update first minimum, second minimum, and position for the next row
        fm = fm2;
        sm = sm2;
        pos = pos2;
    }
    // Return the first minimum which represents the minimum falling path sum
    return fm;
}
};

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/