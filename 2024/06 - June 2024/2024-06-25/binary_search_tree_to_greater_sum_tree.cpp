class Solution {
private:
    int sum = 0;  // A private member variable to keep track of the accumulated sum

    // Helper function to traverse the tree and modify the node values
    void traverse(TreeNode* root) {
        if(root) {  // Check if the current node is not null
            traverse(root->right);  // Traverse the right subtree first
            sum += root->val;  // Add the value of the current node to the sum
            root->val = sum;  // Update the current node's value to the accumulated sum
            traverse(root->left);  // Traverse the left subtree
        }
    }

public:
    // Function to transform the BST to a Greater Sum Tree (GST)
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);  // Call the helper function to start the traversal and transformation
        return root;  // Return the modified tree
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)