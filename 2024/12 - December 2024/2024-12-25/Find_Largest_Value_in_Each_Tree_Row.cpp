class Solution {
public:
    void helper(TreeNode* node, vector<int> &ans, int idx) {

        // Base case: If the current node is NULL, return.
        if(node == NULL) return;

        // If the current index is out of bounds of the 'ans' vector, 
        // push the node's value to the end of the vector.
        if(ans.size() < idx+1) {
            ans.push_back(node->val);
        } 
        // Otherwise, check if the node's value is greater than the 
        // value at the current index in the 'ans' vector.
        else {
            if(ans[idx] < node->val) {
                ans[idx] = node->val; 
            }
        }

        // Recursively call 'helper' on the left and right subtrees, 
        // incrementing the index for each level.
        if(node->left) {
            helper(node->left, ans, idx+1);
        }
        if(node->right)
            helper(node->right, ans, idx+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        // Base case: If the root is NULL, return an empty vector.
        if(root == NULL) return ans;

        // Call the helper function to populate the 'ans' vector.
        helper(root, ans, 0); 
        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N)
