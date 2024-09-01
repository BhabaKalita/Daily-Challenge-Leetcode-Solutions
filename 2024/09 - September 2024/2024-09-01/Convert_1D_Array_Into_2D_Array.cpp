class Solution {
public:
    static vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        const int sz = original.size();

        // Check if the number of elements in the original vector is equal to the product of m and n
        if (sz != m * n) {
            return {}; // Return an empty vector if the dimensions are not compatible
        }

        // Create a 2D vector with the specified dimensions
        vector<vector<int>> ans(m);

        // Iterate through each row of the 2D array
        for (int i = 0; i < m; i++) {
            // Assign a slice of the original vector to the current row
            ans[i].assign(original.begin() + i * n, original.begin() + (i + 1) * n);
        }

        return ans;
    }
};
// TIme Complexity : O(m * n)
// Space Complexity : O(m * n)
