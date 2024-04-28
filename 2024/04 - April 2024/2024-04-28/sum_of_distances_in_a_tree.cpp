class Solution {

public:
vector<unordered_set<int>> tree;
vector<int> res, count;

// Function to calculate the sum of distances in the tree
vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    tree.resize(N);
    res.assign(N, 0); // Initialize the result vector with zeros
    count.assign(N, 1); // Initialize the count vector with ones

    // Populate the tree with edges
    for (auto e : edges) {
        tree[e[0]].insert(e[1]);
        tree[e[1]].insert(e[0]);
    }

    // Perform depth-first search traversal
    dfs(0, -1);

    // Perform a second depth-first search traversal
    dfs2(0, -1);

    return res; // Return the result vector
}

// Depth-first search function
void dfs(int root, int pre) {
    // Traverse the neighbors of the current node
    for (auto i : tree[root]) {
        // Skip the neighbor if it's the parent node
        if (i == pre) continue;

        // Recursively call dfs on the neighbor
        dfs(i, root);

        // Update the count and result vectors
        count[root] += count[i];
        res[root] += res[i] + count[i];
    }
}

// Second depth-first search function
void dfs2(int root, int pre) {
    // Traverse the neighbors of the current node
    for (auto i : tree[root]) {
        // Skip the neighbor if it's the parent node
        if (i == pre) continue;

        // Update the result vector based on the parent's values
        res[i] = res[root] - count[i] + count.size() - count[i];

        // Recursively call dfs2 on the neighbor
        dfs2(i, root);
    }
}
};

/*
Time Complexity: O(N+E)
Space Complexity: O(N)
*/