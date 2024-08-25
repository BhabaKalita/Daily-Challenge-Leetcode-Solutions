class Solution {
public:
    vector<int> num = {}; // Initialize an empty vector to store the post-order traversal

    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) { // Base case: If the root is null, return an empty vector
            return num;
        }

        postorderTraversal(root->left); // Recursively traverse the left subtree
        postorderTraversal(root->right); // Recursively traverse the right subtree

        // Add the root node's value to the vector
        num.push_back(root->val);

        return num; // Return the vector containing the post-order traversal
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)