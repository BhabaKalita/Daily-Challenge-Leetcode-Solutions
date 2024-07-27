class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Define a large number as infinity
        const int inf = 1 << 29;

        // Initialize the cost matrix g with inf, and 0 for diagonal elements
        int g[26][26];
        for (int i = 0; i < 26; ++i) {
            fill(begin(g[i]), end(g[i]), inf);
            g[i][i] = 0;
        }

        // Populate the cost matrix with given conversion costs
        for (int i = 0; i < original.size(); ++i) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            int z = cost[i];
            g[x][y] = min(g[x][y], z);
        }

        // Use the Floyd-Warshall algorithm to find the shortest paths between all pairs of characters
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        // Calculate the minimum cost to transform source to target
        long long ans = 0;
        int n = source.length();
        for (int i = 0; i < n; ++i) {
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            // If characters are different, add the conversion cost
            if (x != y) {
                if (g[x][y] >= inf) {
                    return -1; // If conversion is not possible, return -1
                }
                ans += g[x][y];
            }
        }
        return ans; // Return the total minimum cost
    }
};
// Time Complexity: O(m + n)
// Space Complexity: O(m + n)