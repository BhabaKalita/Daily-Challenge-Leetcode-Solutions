class Solution {
public:
    int ans = 0; // Global variable to store the final sum

    // Depth-first search function to traverse the tree
    void dfs(TreeNode* root, int num) {
        if (!root) return; // Base case: if the node is null, return
        num = num * 10 + root->val; // Calculate the number formed by the path from root to current node

        // If the current node is a leaf node (no children), add the formed number to the final sum
        if (!root->left && !root->right) {
            ans += num;
        }

        // Recursively call dfs for left and right children
        dfs(root->left, num);
        dfs(root->right, num);
    }

    // Main function to calculate the sum of all root-to-leaf numbers
    int sumNumbers(TreeNode* root, int val = 0) {
        if (!root) return 0; // If the tree is empty, return 0
        dfs(root, val); // Start the depth-first search from the root
        return ans; // Return the final sum
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/