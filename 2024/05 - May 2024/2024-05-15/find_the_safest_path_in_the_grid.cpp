class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& g) {
        // Direction vectors for moving right, down, left, and up
        int dir[5] = {1, 0, -1, 0, 1};
        int n = g.size();  // Size of the grid
        queue<array<int, 2>> q;

        // Push all cells with initial safeness factor (value 1) into the queue
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j])
                    q.push({i, j});

        // Perform BFS to propagate safeness factors from initial cells
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (min(x, y) >= 0 && max(x, y) < n && g[x][y] == 0) {
                    g[x][y] = g[i][j] + 1;
                    q.push({x, y});
                }
            }
        }

        // Max heap to prioritize cells with the highest safeness factor
        priority_queue<array<int, 3>> pq;
        pq.push({g[0][0], 0, 0});

        // Perform modified Dijkstra's algorithm to find the path with the maximum safeness factor
        while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
            auto [sf, i, j] = pq.top(); pq.pop();
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (min(x, y) >= 0 && max(x, y) < n && g[x][y] > 0) {
                    pq.push({min(sf, g[x][y]), x, y});
                    g[x][y] *= -1;  // Mark as visited by negating the safeness factor
                }
            }
        }

        // Return the highest safeness factor on the path, adjusted by subtracting 1
        return pq.top()[0] - 1;
    }
};
/*
Time Complexity: O(n^2log(n))
Space Complexity: O(n^2)
*/