class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // If depth is 1, create a new node as the new root and attach the current root as its left child.
        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        // Otherwise, perform a level-order traversal using a queue.
        queue<TreeNode*> q;
        int count = 0;
        q.push(root);

        // Traverse each level until depth - 1.
        while (!q.empty()) {
            int n = q.size(); // Number of nodes in the current level.

            count++; // Increment the level counter.

            // Process each node in the current level.
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                // If the current level is not depth - 1, continue traversal.
                if (count != depth - 1) {
                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                } 
                // If the current level is depth - 1, add new nodes as children of the current nodes.
                else {
                    TreeNode* newNodeLeft = new TreeNode(val);
                    newNodeLeft->left = curr->left;
                    curr->left = newNodeLeft;

                    TreeNode* newNodeRight = new TreeNode(val);
                    newNodeRight->right = curr->right;
                    curr->right = newNodeRight;
                }
            }
        }
        return root; // Return the modified root.
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/