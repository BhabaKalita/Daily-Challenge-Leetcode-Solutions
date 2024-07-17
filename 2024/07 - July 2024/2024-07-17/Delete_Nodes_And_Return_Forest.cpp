class Solution {
    // A boolean array to keep track of nodes to delete
    bool set[1001] = {};

    private:
    // Depth-first search (DFS) function to traverse the tree and delete nodes
    void dfs(TreeNode* &root, bool flag, vector<TreeNode*> &res) {
        if (root == nullptr) return; // Base case: if the current node is null, return

        // Recursively traverse the left and right subtrees
        dfs(root->left, set[root->val], res);
        dfs(root->right, set[root->val], res);

        // If the current node is not to be deleted and it is a root of a subtree
        if (!set[root->val] && flag) res.push_back(root);

        // If the current node is to be deleted, set it to null
        if (set[root->val]) root = nullptr;
    }

    public:
    // Function to delete nodes and return the forest
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;

        // Mark nodes to be deleted
        for (int x : to_delete) {
            set[x] = true;
        }

        // Call DFS with the root node and initial flag as true
        dfs(root, true, res);

        return res; // Return the resulting forest
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N)