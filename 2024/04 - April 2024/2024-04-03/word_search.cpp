// Function to check if a word exists in the 2D board
bool exist(vector<vector<char>>& board, string word) {
    // Iterate through each cell of the board
    for (unsigned int i = 0; i < board.size(); i++) {
        for (unsigned int j = 0; j < board[0].size(); j++) {
            // If the DFS search starting from cell (i, j) finds the word, return true
            if (dfs(board, i, j, word))
                return true;
        }
    }
    // If the word is not found after searching all cells, return false
    return false;
}

// Depth-first search function
bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    // If the entire word is found, return true
    if (!word.size())
        return true;

    // Check for out-of-bounds or if the current cell does not match the first character of the word
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
        return false;

    // Save the current character of the board and mark the current cell as visited
    char c = board[i][j];
    board[i][j] = '*';

    // Extract the remaining characters of the word
    string s = word.substr(1);

    // Recursively search in all four directions (up, down, left, right)
    bool ret = dfs(board, i - 1, j, s) || dfs(board, i + 1, j, s) || dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s);

    // Restore the original character of the board
    board[i][j] = c;

    // Return the result of the DFS search
    return ret;
}
/*
Time Complexity: O(m*n*4*k)
Space Complexity: O(k)
*/