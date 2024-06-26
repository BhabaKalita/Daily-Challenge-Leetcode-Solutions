class Solution {
private:
    // Helper function to perform in-order traversal and collect node values in a vector
    void inOrder(TreeNode* root, vector<int> &arr) {
        if (root == NULL) return;  // Base case: If the node is null, return
        inOrder(root->left, arr);  // Recurse on the left subtree
        arr.push_back(root->val);  // Add the current node's value to the array
        inOrder(root->right, arr); // Recurse on the right subtree
    }

    // Helper function to convert a sorted array to a balanced BST
    TreeNode* inOrderToBST(int s, int e, vector<int> &arr) {
        if (s > e) return NULL;  // Base case: If start index exceeds end index, return null

        int mid = (s + e) / 2;  // Find the middle element of the current segment
        TreeNode* root = new TreeNode(arr[mid]);  // Create a new tree node with the middle element

        root->left = inOrderToBST(s, mid - 1, arr);  // Recursively construct the left subtree
        root->right = inOrderToBST(mid + 1, e, arr); // Recursively construct the right subtree
        return root;  // Return the root of the constructed subtree
    }

public:
    // Main function to balance the BST
    TreeNode* balanceBST(TreeNode* root) {
        if (root == NULL) return root;  // If the input tree is null, return null

        vector<int> inOrderVal;  // Vector to store the in-order traversal values
        inOrder(root, inOrderVal);  // Perform in-order traversal and fill the vector

        return inOrderToBST(0, inOrderVal.size() - 1, inOrderVal);  // Convert the sorted array to a balanced BST
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/