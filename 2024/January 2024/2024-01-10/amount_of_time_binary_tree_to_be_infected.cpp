// Adjacency list for representing an undirected graph
unordered_map<int, vector<int>> v;

// Function to create an undirected graph for every parent-child relationship using DFS
void createGraph(TreeNode* root, int parent = -1) {
    if (!root) return;

    int value = root->val;

    // Connect the parent and child in both directions
    if (parent != -1) {
        v[parent].push_back(value);
        v[value].push_back(parent);
    }

    // Recursively create the graph for the left and right subtrees
    createGraph(root->left, value);
    createGraph(root->right, value);
}

// Function to calculate the amount of time required to reach all nodes starting from a given node using BFS
int amountOfTime(TreeNode* root, int start) {
    // Create the graph of the given tree
    createGraph(root);

    // Start BFS
    queue<int> q;
    unordered_map<int, bool> seen;
    q.push(start);
    seen[start] = true;
    int time = 0;

    // Perform BFS traversal
    for (; q.size(); time++) {
        int n = q.size();

        // Process nodes at the current level
        while (n--) {
            auto node = q.front();
            q.pop();

            // Visit neighbors of the current node
            for (auto i : v[node]) {
                if (!seen[i]) {
                    q.push(i);
                    seen[i] = true;
                }
            }
        }
    }

    // Return the total time taken (excluding the initial node)
    return time - 1;
}

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/