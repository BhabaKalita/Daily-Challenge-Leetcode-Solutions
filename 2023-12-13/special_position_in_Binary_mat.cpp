#include <vector>
using namespace std;

class Solution {
public:
    // Function to count special positions in a binary matrix
    int numSpecial(vector<vector<int>>& mat) {
        // Get the number of rows and columns in the matrix
        int row = mat.size();
        int col = mat[0].size();

        // Arrays to store the count of 1s in each row and each column
        vector<int> tempR(row), tempC(col);

        // Count the number of 1s in each row and column
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 1) {
                    ++tempR[i]; // Increment count for the current row
                    ++tempC[j]; // Increment count for the current column
                }
            }
        }

        // Count the number of special positions where there is only one 1 in both its row and column
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 1 && tempR[i] == 1 && tempC[j] == 1)
                    count++; // Increment count for special position
            }
        }

        // Return the total count of special positions
        return count;
    }
};
