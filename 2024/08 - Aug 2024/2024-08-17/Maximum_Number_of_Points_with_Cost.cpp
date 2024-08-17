class Solution {
public:

    // Function to calculate the maximum points collectible
    long long maxPoints(vector<vector<int>>& grid) {
        // Get the width (number of columns) of the grid
        const int width = grid[0].size();

        // Vectors to store the current and previous row's maximum points
        vector<long long> current(width), previous(width);

        // Variable to store the maximum score
        long long maxScore = 0;

        // Iterate through each row in the grid
        for (const auto& level : grid) {
            long long peak = 0;

            // Forward sweep: Calculate the maximum points you can get moving left-to-right
            for (int i = 0; i < width; ++i) {
                // Update peak to be the maximum of moving to the left (with a -1 penalty) or staying in the same column
                peak = max(peak - 1, previous[i]);
                // Set the current maximum for this column in the current row
                current[i] = peak;
            }

            peak = 0;

            // Backward sweep: Calculate the maximum points you can get moving right-to-left
            for (int i = width - 1; i >= 0; --i) {
                // Update peak to be the maximum of moving to the right (with a -1 penalty) or staying in the same column
                peak = max(peak - 1, previous[i]);
                // Update the current maximum to be the best between the current value and the right-to-left peak,
                // and add the value of the current cell in the grid
                current[i] = max(current[i], peak) + level[i];
            }

            // Swap the current row's results to the previous row for the next iteration
            previous.swap(current);
        }

        // Compute the final maximum score from the last row of results
        maxScore = *max_element(previous.begin(), previous.end());

        // Return the maximum score found
        return maxScore;
    }
};
// Time Complexity: O(m*n)
// Space Complexity: O(n)