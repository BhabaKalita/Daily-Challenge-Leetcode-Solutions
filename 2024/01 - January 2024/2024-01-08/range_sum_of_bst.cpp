class Solution {
public:
    int sum = 0;

    // Helper function for inorder traversal to calculate the sum within the specified range [L, H].
    int inorder(TreeNode* root, int L, int H) {
        if (!root) return 0; // Base case: if the current node is null, return 0.

        // Traverse the left subtree.
        inorder(root->left, L, H);

        // Check if the value of the current node is within the specified range [L, H].
        if (root->val >= L && root->val <= H)
            sum += root->val; // If yes, add the value to the sum.

        // Traverse the right subtree.
        inorder(root->right, L, H);

        return sum;
    }

    // Main function to calculate the sum of values in the BST within the specified range [L, H].
    int rangeSumBST(TreeNode* root, int L, int H) {
        if (!root) return 0; // If the tree is empty, return 0.
        return inorder(root, L, H); // Call the helper function for inorder traversal.
        // return sum; // Note: Returning sum here is not necessary as the sum is already updated in the helper function.
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(H)
*/