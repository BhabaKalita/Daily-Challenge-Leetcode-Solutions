class Solution {
public:
    // Function to find the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; // Initialize diameter
        solve(root, diameter); // Call the helper function
        return diameter; // Return the diameter of the binary tree
    }

    // Helper function to calculate the height of the binary tree
    int solve(TreeNode* root, int &diameter) {
        if (!root) return 0; // Base case: if root is null, return 0

        // Recursive calls to find the heights of the left and right subtrees
        int left_height = solve(root->left, diameter);
        int right_height = solve(root->right, diameter);

        // Update the diameter if the sum of heights of left and right subtrees is greater
        diameter = max(diameter, left_height + right_height);

        // Return the height of the current node's subtree
        return max(left_height, right_height) + 1;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/