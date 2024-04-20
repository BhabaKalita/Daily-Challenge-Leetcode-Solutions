class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();
        vector<vector<int>> res;

        // Iterate through each cell of the land matrix
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {

                // If the current cell is not part of any farmland, continue to the next cell
                if(land[i][j] == 0) continue;

                // Find the rightmost column of the current farmland
                int c1 = j;
                while(c1 < col && land[i][c1] == 1)
                    c1++;

                // Find the bottommost row of the current farmland
                int r1 = i;
                while(r1 < row && land[r1][j] == 1)
                    r1++;

                // Adjust the indices to represent the bottom-right corner of the farmland
                c1 = c1 == 0 ? c1 : c1 - 1;
                r1 = r1 == 0 ? r1 : r1 - 1;

                // Store the coordinates of the top-left and bottom-right corners of the farmland
                res.push_back({i, j, r1, c1});

                // Mark the current farmland as visited (set all its cells to 0)
                for(int k = i; k <= r1; k++) {
                    for(int l = j; l <= c1; l++) {
                        land[k][l] = 0;
                    }
                }

            }
        }
        return res;
    }
};

/*
Time Complexity: O(m*n)
Spacce Complexity: O(k)
*/