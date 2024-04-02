class Solution {
public:
    int maxAncestorDiff(TreeNode* root, int mn = 100000, int mx = 0) {
        // Base case: if the node is null, return the difference between max and min values
        if (!root) return mx - mn;

        // Update the maximum and minimum values based on the current node's value
        mx = max(mx, root->val);
        mn = min(mn, root->val);

        // Recursively calculate the maximum difference for the left and right subtrees
        return max(maxAncestorDiff(root->left, mn, mx), maxAncestorDiff(root->right, mn, mx));
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/