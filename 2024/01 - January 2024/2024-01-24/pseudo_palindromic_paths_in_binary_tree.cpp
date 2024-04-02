#include <vector>

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        // Initialize a vector to store counts of digits (from 1 to 9).
        vector<int> digits(10, 0);
        // Start DFS traversal from the root.
        return dfs(root, digits);
    }

private:
    // Recursive function for DFS traversal.
    int dfs(TreeNode* root, vector<int>& digits) {
        // Base case: If the current node is NULL, return 0.
        if (root == nullptr)
            return 0;

        // Increment the count of the current digit.
        digits[root->val]++;

        // If the current node is a leaf, check if the path is pseudo-palindromic.
        if (root->left == nullptr && root->right == nullptr) {
            int cnt = countOdd(digits);
            digits[root->val]--;  // Backtrack by decrementing the count.

            // Return 1 if the count of odd digits is at most 1, indicating a pseudo-palindromic path.
            return (cnt <= 1) ? 1 : 0;
        }

        // Recursively traverse the left and right subtrees.
        int leftCount = dfs(root->left, digits);
        int rightCount = dfs(root->right, digits);

        // Backtrack by decrementing the count of the current digit.
        digits[root->val]--;

        // Return the sum of counts from left and right subtrees.
        return leftCount + rightCount;
    }

    // Helper function to count the number of digits with odd occurrences.
    int countOdd(const vector<int>& digits) {
        int cnt = 0;

        // Iterate through the digits (from 1 to 9) and count odd occurrences.
        for (int i = 1; i < 10; ++i) {
            if ((digits[i]) & 1) // Using bitwise AND to check if the count is odd.
                cnt++;
        }

        return cnt;
    }
};

/*
Time Complexity: O(N), where N is the number of nodes in the binary tree.
Space Complexity: O(H), where H is the height of the binary tree.
*/
