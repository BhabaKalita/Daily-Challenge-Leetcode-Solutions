class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        // If the node is a leaf, return its value as a boolean.
        if (root->val < 2) 
            return root->val;
        // If the node represents OR operation (value 2), 
        // evaluate the left and right subtrees and return their OR result.
        else if (root->val == 2) 
            return evaluateTree(root->left) || evaluateTree(root->right);
        // If the node represents AND operation (value 3), 
        // evaluate the left and right subtrees and return their AND result.
        else 
            return evaluateTree(root->left) && evaluateTree(root->right);
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/