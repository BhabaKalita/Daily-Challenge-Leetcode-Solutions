class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        // Base case: If both trees are null, they are equivalent
        if (root1 == NULL && root2 == NULL) {
            return true;
        }

        // If only one tree is null, they are not equivalent
        if (root1 == NULL || root2 == NULL) {
            return false;
        }

        // If the root values are different, the trees are not equivalent
        if (root1->val != root2->val) {
            return false;
        }

        // Try both possibilities: left-left/right-right and left-right/right-left
        bool take = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        bool notTake = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);

        // Return true if either possibility leads to equivalent trees
        return take || notTake;
    }
};

// Time Complexity: O(n)
// Reason:
// - The `flipEquiv` function recursively explores both subtrees of each node.
// - In the worst case, the recursion tree can have a depth of n (the number of nodes in the tree).
// - At each level of the recursion, constant time operations (comparisons, function calls) are performed.
// - Therefore, the overall time complexity is O(n).

// Space Complexity: O(n)
// Reason:
// - The recursion stack can go up to n levels deep in the worst case (for a skewed tree).
// - Each level of the recursion stores the current nodes being compared.
// - Therefore, the space complexity is O(n).
