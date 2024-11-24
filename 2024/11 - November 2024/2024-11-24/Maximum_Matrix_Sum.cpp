class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minVal = INT_MAX;
        long long sum = 0;
        int negCount = 0;

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] < 0) {
                    negCount++;
                }
                int absVal = abs(matrix[i][j]);
                minVal = min(minVal, absVal);
                sum += absVal;
            }
        }

        if(negCount % 2 == 0)
            return sum;
        return sum - 2 * minVal;
    }
};
/*
Time Complexity: O(m×n)O(m×n), where mm is the number of rows and nn is the number of columns, for iterating through the matrix.
Space Complexity: O(1)O(1), as no additional space is used beyond the variables.
*/
