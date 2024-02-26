// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to check if two binary trees are the same
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both trees are empty, they are identical
        if (!p && !q)
            return true;

        // If one tree is empty while the other is not, they are not identical
        // Also, if the values of the current nodes are different, they are not identical
        if (!p || !q || p->val != q->val)
            return false;

        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/