class Solution {
public:
    void solve(Node* &root, vector<int> &ans) {
        if(!root) return; // Base case: If the root is null, return

        for(Node* child:root->children) {
            solve(child, ans); // Recursively traverse the children
            ans.push_back(child->val); // Add the child's value to the answer vector
        }
    }

    vector<int> postorder(Node* root) {
        vector<int> ans; // Initialize an empty vector to store the post-order traversal
        solve(root, ans); // Recursively traverse the root and its children
        if(root != NULL) {
            ans.push_back(root->val); // Add the root's value to the answer vector
        }
        return ans; // Return the vector containing the post-order traversal
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)