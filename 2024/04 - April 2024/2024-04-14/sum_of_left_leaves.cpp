class Solution {
public:
    // Function to calculate the sum of left leaves in a binary tree
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        // If the root is null, return 0
        if (!root) 
            return 0;

        // If the root is a leaf node, return its value if it's a left leaf, otherwise return 0
        if (!root->left && !root->right) 
            return isLeft ? root->val : 0;

        // Recursively traverse the left and right subtrees
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(h)
*/