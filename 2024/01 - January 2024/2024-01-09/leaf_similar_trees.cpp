class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // Stacks to perform depth-first traversal
        stack<TreeNode*> s1, s2;
        // Initialize stacks with the roots of the respective trees
        s1.push(root1);
        s2.push(root2);

        // Continue traversal until both stacks are empty
        while (!s1.empty() && !s2.empty()) {
            // Check if the leaf sequences are not similar
            if (dfs(s1) != dfs(s2)) {
                return false;
            }
        }

        // If both stacks are empty, the leaf sequences are similar
        return s1.empty() && s2.empty();
    }

    // Function to perform depth-first traversal and return the value of the first leaf node encountered
    int dfs(stack<TreeNode*>& s) {
        while (true) {
            // Pop the top node from the stack
            TreeNode* node = s.top();
            s.pop();

            // Push left and right children if they exist
            if (node->left) {
                s.push(node->left);
            }
            if (node->right) {
                s.push(node->right);
            }

            // If the node is a leaf, return its value
            if (!node->left && !node->right) {
                return node->val;
            }
        }
    }
};

/*
Time Complexity: O(N + M), where N and M are the number of nodes in the two trees
Space Complexity: O(H1 + H2), where H1 and H2 are the heights of the two trees
*/