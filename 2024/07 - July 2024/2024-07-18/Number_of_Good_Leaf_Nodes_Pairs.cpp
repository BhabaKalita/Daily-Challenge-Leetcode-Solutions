/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    /**
     * Helper function to recursively traverse the tree and count pairs of nodes
     * whose distance is less than or equal to the given distance.
     *
     * @param root The current node in the binary tree.
     * @param distance The maximum allowable distance between two leaf nodes.
     * @param cnt Reference to the counter for valid pairs.
     * @return A vector of distances from the current node to its leaf nodes.
     */
    vector<int> recur(TreeNode* root, int distance, int &cnt) {
        // Base case: if the node is null, return an empty list.
        if (!root) return {};

        // If the node is a leaf, return a list containing the distance 1.
        if (!root->left && !root->right) return {1};

        // Recursively call the function on the left and right subtrees.
        vector<int> left = recur(root->left, distance, cnt);
        vector<int> right = recur(root->right, distance, cnt);

        // Compare distances from left and right children to count valid pairs.
        for (int x : left) {
            for (int y : right) {
                // Check if the sum of distances is within the given distance.
                if (x > 0 && y > 0) {
                    if (x + y <= distance) cnt++;
                }
            }
        }

        // Create a list to store distances incremented by 1.
        vector<int> ans;
        for (int x : left) {
            // Only include distances that are less than the given distance.
            if (x > 0 && x < distance) {
                ans.push_back(x + 1);
            }
        }

        for (int x : right) {
            // Only include distances that are less than the given distance.
            if (x > 0 && x < distance) {
                ans.push_back(x + 1);
            }
        }

        // Return the list of distances.
        return ans;
    }

    /**
     * Main function to count the number of pairs of leaf nodes whose distance is
     * less than or equal to the given distance.
     *
     * @param root The root of the binary tree.
     * @param distance The maximum allowable distance between two leaf nodes.
     * @return The number of pairs of leaf nodes within the given distance.
     */
    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        // Call the recursive helper function.
        recur(root, distance, cnt);
        return cnt;
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)