#include <queue> // Include necessary header file

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // Initialize a queue for level-order traversal
        queue<TreeNode*> q;
        // Push the root node into the queue
        q.push(root);

        // Perform level-order traversal
        while (!q.empty()) {
            // Get the front node of the queue
            root = q.front();
            // Remove the front node from the queue
            q.pop();

            // Check if the right child of the current node exists, if yes, push it into the queue
            if (root->right)
                q.push(root->right);

            // Check if the left child of the current node exists, if yes, push it into the queue
            if (root->left)
                q.push(root->left);
        }
        // Return the value of the last node processed, which is the leftmost node at the deepest level
        return root->val;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/