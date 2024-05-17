class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Recursively remove leaf nodes with the target value from the left subtree
        if (root->left) 
            root->left = removeLeafNodes(root->left, target);

        // Recursively remove leaf nodes with the target value from the right subtree
        if (root->right) 
            root->right = removeLeafNodes(root->right, target);

        // If the current node is a leaf and its value is equal to the target,
        // return nullptr to remove this leaf node
        return (root->left == nullptr && root->right == nullptr && root->val == target) ? nullptr : root;
    }
};

/*
Time Complexity: O(n) where n is the number of nodes in the binary tree.
Space Complexity: O(n)
*/