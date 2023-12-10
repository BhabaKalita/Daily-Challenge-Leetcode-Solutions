#include <vector>
using namespace std;

class Solution {
public:
  // Function to calculate the transpose of a given matrix
  vector<vector<int>> transpose(vector<vector<int>> &matrix) {
    // Get the number of rows and columns in the original matrix
    int row = matrix.size();
    int col = matrix[0].size();

    // Create a matrix to store the transpose with swapped rows and columns
    vector<vector<int>> res(col, vector<int>(row, 0));

    // Fill in the transpose matrix by swapping rows and columns
    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        res[i][j] = matrix[j][i];
      }
    }

    // Return the transposed matrix
    return res;
  }
};