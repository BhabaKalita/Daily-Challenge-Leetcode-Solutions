#include <vector>
using namespace std;

// TreeNode definition is assumed
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Global vector to store values at each level
vector<int> vals;

// Function to check if a binary tree is an Even-Odd Tree
bool isEvenOddTree(TreeNode* n, size_t l = 0) {
    // Base case: If the current node is nullptr, return true
    if (n == nullptr)
        return true;

    // Check if the current node's value violates the Even-Odd property
    if (n->val % 2 == l % 2)
        return false;

    // Resize the vector to accommodate values up to level 'l'
    vals.resize(max(vals.size(), l + 1));

    // Check if the current node's value violates the strict increasing order
    if (vals[l] != 0 && ((l % 2 && vals[l] <= n->val) || (!(l % 2) && vals[l] >= n->val)))
        return false;

    // Store the current node's value at its level in the vector
    vals[l] = n->val;

    // Recursively check the left and right subtrees
    return isEvenOddTree(n->left, l + 1) && isEvenOddTree(n->right, l + 1);
}
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/