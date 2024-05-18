class Solution {
public:
    // Helper function to solve the problem recursively.
    int solve(TreeNode* root, int &count) {
        if (!root) return 0;

        // Recursively solve for the left and right subtrees.
        int l = solve(root->left, count);
        int r = solve(root->right, count);

        // Update the move count with the absolute values of l and r.
        count += abs(l) + abs(r);

        // Return the net number of coins at this node after balancing.
        return l + r + root->val - 1;
    }

    // Main function to distribute coins in the binary tree.
    int distributeCoins(TreeNode* root) {
        int count = 0;
        solve(root, count);   
        return count;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/