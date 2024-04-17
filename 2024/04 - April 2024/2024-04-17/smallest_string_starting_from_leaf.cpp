class Solution {
public:
    string smallestFromLeaf(TreeNode* root, string s = "") {
        // Add current node's character value to the beginning of the string
        s = string(1, 'a' + root->val) + s;

        // If the current node is a leaf node, return the constructed string
        if (root->left == nullptr && root->right == nullptr) 
            return s;

        // Recursively find the smallest string from the left and right subtrees
        string leftStr = root->left ? smallestFromLeaf(root->left, s) : "|";
        string rightStr = root->right ? smallestFromLeaf(root->right, s) : "|";

        // Return the lexicographically smallest string among left and right subtrees
        return min(leftStr, rightStr);
    }
};

/*
Time Complexity: O(n)
Space complexity: O(n)
*/