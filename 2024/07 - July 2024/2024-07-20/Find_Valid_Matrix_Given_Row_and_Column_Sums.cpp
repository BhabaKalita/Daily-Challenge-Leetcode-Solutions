class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // Get the dimensions of the matrix
        int m = rowSum.size(), n = colSum.size();

        // Initialize the result matrix with zeros
        vector<vector<int>> vec(m, vector<int>(n, 0));

        // Initialize pointers for row and column
        int i = 0, j = 0;

        // Iterate until we process all rows and columns
        while (i < m && j < n) {
            // Set the value at the current cell to the minimum of the current rowSum and colSum
            vec[i][j] = min(rowSum[i], colSum[j]);

            // Update the rowSum and colSum by subtracting the value just set
            rowSum[i] -= vec[i][j];
            colSum[j] -= vec[i][j];

            // Move to the next row if the current rowSum is zero
            if (rowSum[i] == 0) i++;
            // Move to the next column if the current colSum is zero
            if (colSum[j] == 0) j++;
        }

        // Return the constructed matrix
        return vec;
    }
};
// Time Complexity: O(m+n)
// Space Complexity: O(m*n)