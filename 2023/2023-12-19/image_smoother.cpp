#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row = img.size();
        int col = img[0].size();

        // Initialize the answer matrix with the same size as the input image
        vector<vector<int>> ans(row, vector<int>(col, 0));

        // Iterate through each pixel in the input image
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int avg = 0, cnt = 0;

                // Iterate through the 3x3 neighborhood of the current pixel
                for (int x = max(i - 1, 0); x < min(i + 2, row); x++) {
                    for (int y = max(j - 1, 0); y < min(j + 2, col); y++) {
                        avg += img[x][y];
                        cnt++;
                    }
                }

                // Calculate the average value and store it in the answer matrix
                ans[i][j] = avg / cnt;
            }
        }

        // Return the smoothed image
        return ans;
    }
};

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/