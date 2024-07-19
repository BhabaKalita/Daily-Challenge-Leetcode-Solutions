class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows = matrix.size();       // Number of rows in the matrix
        int cols = matrix[0].size();    // Number of columns in the matrix

        // Initialize vectors to store the minimum values in each row
        // and the maximum values in each column
        vector<int> row_minimums(rows, INT_MAX);
        vector<int> col_maximums(cols, 0);

        // Iterate through the matrix to find the row minimums and column maximums
        for (int row_ind = 0; row_ind < rows; ++row_ind) {
            for (int col_ind = 0; col_ind < cols; ++col_ind) {
                int el = matrix[row_ind][col_ind];
                row_minimums[row_ind] = min(row_minimums[row_ind], el); // Update the row minimum
                col_maximums[col_ind] = max(col_maximums[col_ind], el); // Update the column maximum
            }
        }

        // Iterate through the matrix again to find the lucky numbers
        for (int row_ind = 0; row_ind < rows; ++row_ind) {
            for (int col_ind = 0; col_ind < cols; ++col_ind) {
                int el = matrix[row_ind][col_ind];
                // Check if the current element is both the row minimum and the column maximum
                if (el == row_minimums[row_ind] && el == col_maximums[col_ind]) {
                    return {el}; // Return the lucky number
                }
            }
        }

        return {}; // Return an empty vector if no lucky number is found
    }
};
// Time Complexity: O(row*col)
// Space Complexity: O(row+col)