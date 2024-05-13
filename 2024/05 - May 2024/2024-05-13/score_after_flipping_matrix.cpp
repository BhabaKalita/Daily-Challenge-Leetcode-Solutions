int matrixScore(vector<vector<int>> A) {
    // Number of rows
    int M = A.size();
    // Number of columns
    int N = A[0].size();
    // Initialize the result with the score of the leftmost bit in each row
    int res = (1 << (N - 1)) * M;

    // Iterate through each column
    for (int j = 1; j < N; j++) {
        // Initialize the count of elements matching the first element of the column
        int cur = 0;
        // Count elements in the current column matching the first element of the column
        for (int i = 0; i < M; i++) {
            cur += A[i][j] == A[i][0];
        }
        // Update the result based on the maximum count of matching or non-matching elements
        res += max(cur, M - cur) * (1 << (N - j - 1));
    }
    return res;
}

/*
Time Complexity: O(M * N)
Space Complexity: O(1)
*/