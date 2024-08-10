class Solution {
    vector<int> parent;  // Vector to store the parent of each node in the Union-Find structure
    vector<int> rank;    // Vector to store the rank (depth) of each tree in the Union-Find structure
    int count;           // Variable to keep track of the number of regions formed

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();  // Get the size of the grid (number of rows/columns)
        int dots = n + 1;     // The grid has n+1 dots (corners) in each dimension
        parent.resize(dots * dots);  // Resize the parent vector to handle all dots in the grid
        rank.resize(dots * dots, 1); // Initialize rank for each dot to 1
        count = 0;                   // Initialize the region count to zero

        // Initialize the Union-Find structure
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;  // Each dot is its own parent initially
        }

        // Connect boundaries to the top-left corner (0,0)
        for (int i = 0; i < dots; ++i) { // Iterate over each row of dots
            for (int j = 0; j < dots; ++j) { // Iterate over each column of dots
                if (i == 0 || j == 0 || i == n || j == n) { // Check if the dot is on the boundary
                    int cell = i * dots + j;  // Calculate the 1D index of the dot
                    unionSets(0, cell);       // Union this boundary dot with the top-left corner (0,0)
                }
            }
        }

        // Process each cell in the grid to connect regions based on slashes
        for (int i = 0; i < n; ++i) { // Iterate over each row in the grid
            for (int j = 0; j < n; ++j) { // Iterate over each column in the grid
                if (grid[i][j] == '\\') { // If the cell contains a backslash
                    int cell1 = i * dots + j;               // Top-left corner dot of the cell
                    int cell2 = (i + 1) * dots + (j + 1);   // Bottom-right corner dot of the cell
                    unionSets(cell1, cell2);  // Union these two dots
                } else if (grid[i][j] == '/') { // If the cell contains a forward slash
                    int cell1 = (i + 1) * dots + j;         // Bottom-left corner dot of the cell
                    int cell2 = i * dots + (j + 1);         // Top-right corner dot of the cell
                    unionSets(cell1, cell2);  // Union these two dots
                }
            }
        }

        return count; // Return the total number of regions formed
    }

private:
    // Function to perform the union operation on two sets
    void unionSets(int a, int b) {
        int parentA = find(a);  // Find the root of the set containing 'a'
        int parentB = find(b);  // Find the root of the set containing 'b'
        if (parentA == parentB) { // If both elements have the same root
            count++;  // Increment the region count as this forms a cycle
        } else {
            // Union by rank to keep the tree balanced
            if (rank[parentA] > rank[parentB]) { 
                parent[parentB] = parentA;  // Attach the smaller tree under the larger tree
            } else if (rank[parentA] < rank[parentB]) {
                parent[parentA] = parentB;  // Attach the smaller tree under the larger tree
            } else {
                parent[parentB] = parentA;  // Attach one tree under the other and increase rank
                rank[parentA]++;
            }
        }
    }

    // Function to find the root of the set containing 'a' (with path compression)
    int find(int a) {
        if (parent[a] == a) {  // If 'a' is the root of its set
            return a;  // Return 'a' as the root
        }
        return parent[a] = find(parent[a]);  // Recursively find the root and perform path compression
    }
};
// Time Complexity: O(n^2×log(n))
// Space Complexity: O(n^2)