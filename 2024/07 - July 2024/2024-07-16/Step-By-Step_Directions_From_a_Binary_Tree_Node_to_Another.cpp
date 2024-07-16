class Solution {
public:
    // Helper function to find the path from the root to the node with value 'val'
    bool find(TreeNode* n, int val, string& path) {
        // If the current node's value matches 'val', return true
        if (n->val == val)
            return true;
        // Recursively search in the left subtree
        if (n->left && find(n->left, val, path))
            path.push_back('L'); // If found in left subtree, append 'L' to path
        // Recursively search in the right subtree
        else if (n->right && find(n->right, val, path))
            path.push_back('R'); // If found in right subtree, append 'R' to path
        // Return true if the path is not empty (i.e., 'val' was found)
        return !path.empty();
    }

    // Main function to get directions from startValue to destValue
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s_p, d_p; // Strings to store paths from root to startValue and destValue
        find(root, startValue, s_p); // Find path to startValue
        find(root, destValue, d_p);  // Find path to destValue
        // Remove common suffix from both paths
        while (!s_p.empty() && !d_p.empty() && s_p.back() == d_p.back()) {
            s_p.pop_back();
            d_p.pop_back();
        }
        // Construct the result string
        return string(s_p.size(), 'U') + string(rbegin(d_p), rend(d_p));
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)