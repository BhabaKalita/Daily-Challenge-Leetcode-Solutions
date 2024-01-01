#include <vector>

using namespace std;

class Solution {
public:
    // Function to calculate ones minus zeros for each element in the grid
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        // Vectors to store the sum of ones for each row and column
        vector<int> rowSum(row, 0), colSum(col, 0);

        // Calculate rowSum and colSum
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        // Update grid with ones minus zeros for each element
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // Formula: rowSum + colSum - (number of ones in row) - (number of ones in column)
                grid[i][j] = rowSum[i] + colSum[j] - (row - rowSum[i]) - (col - colSum[j]);
            }
        }

        return grid;
    }
};

/*
Time Complexity: O(row * col)
Space Complexity: O(max(row, col))
*/
