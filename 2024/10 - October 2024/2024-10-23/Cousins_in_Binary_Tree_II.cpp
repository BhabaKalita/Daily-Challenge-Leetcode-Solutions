class Solution {
public:
    // Main function to replace values in the tree
    TreeNode* replaceValueInTree(TreeNode* root) {
        // The root node's value is always set to 0.
        root->val = 0;
        
        // Start the DFS traversal with the root node wrapped in a vector (array of current level nodes).
        dfs(vector<TreeNode*> {root});
        
        // Return the modified tree.
        return root;
    }

    // Helper function for Depth First Search (DFS) to process each level of the tree
    void dfs(vector<TreeNode*> arr) {
        // If the array of nodes for the current level is empty, return.
        if(arr.empty())
            return;
        
        int sum = 0;  // Initialize sum to store the total of all child node values at this level.
        
        // First pass: Calculate the sum of the values of all the children of nodes at this level.
        for(auto node : arr) {
            if(!node) continue;  // Skip null nodes.
            
            // Add the value of the left child if it exists.
            if(node->left) sum += node->left->val;
            
            // Add the value of the right child if it exists.
            if(node->right) sum += node->right->val;
        }

        vector<TreeNode*> childArr;  // Vector to store child nodes for the next level.

        // Second pass: Update node values and prepare the child nodes for the next DFS call.
        for(auto node : arr) {
            int curSum = 0;  // Initialize curSum to store the sum of the current node's left and right child values.

            // Sum up the current node's children's values.
            if(node->left) curSum += node->left->val;
            if(node->right) curSum += node->right->val;

            // Update the left child's value to (total sum - current node's children's sum) and push to the next level.
            if(node->left) {
                node->left->val = sum - curSum;
                childArr.push_back(node->left);
            }

            // Update the right child's value to (total sum - current node's children's sum) and push to the next level.
            if(node->right) {
                node->right->val = sum - curSum;
                childArr.push_back(node->right);
            }
        }

        // Recursively call DFS on the next level of nodes (childArr).
        dfs(childArr);
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(n)
*/
