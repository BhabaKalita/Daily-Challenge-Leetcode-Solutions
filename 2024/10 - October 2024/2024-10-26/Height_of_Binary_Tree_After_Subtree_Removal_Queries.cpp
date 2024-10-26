class Solution {
public:
    // Vectors to store information for each node in the tree
    vector<int> depth, levelArr, max1, max2;

    // Recursive function to calculate the depth of each node
    int height(TreeNode* root, int level) {
        // Base case: if the node is null, return 0
        if (!root) return 0;

        // Store the level of the current node in levelArr based on its value
        levelArr[root->val] = level;

        // Recursively calculate the depth of left and right children, 
        // then assign the maximum of the two to the current node's depth
        depth[root->val] = 1 + max(height(root->left, level + 1), height(root->right, level + 1));

        // Check and update the maximum depths for this level
        if (max1[level] < depth[root->val]) {
            // If the current node has a greater depth than max1 at this level,
            // update max2 with the previous max1 value, then update max1
            max2[level] = max1[level];
            max1[level] = depth[root->val];
        } else if (max2[level] < depth[root->val]) {
            // If current node's depth is greater than max2 (but less than max1), update max2
            max2[level] = depth[root->val];
        }

        // Return the depth of the current node
        return depth[root->val];
    }

    // Main function to process tree queries
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Initialize vectors to handle large inputs up to 100,000 nodes
        depth.resize(100001, 0);
        levelArr.resize(100001, 0);
        max1.resize(100001, 0);
        max2.resize(100001, 0);

        // Calculate the depth and the maximum depths for each level
        height(root, 0);

        // Process each query
        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];          // Current query node
            int level = levelArr[q];      // Get the level of the query node

            // Determine the answer based on whether the node's depth matches max1 or max2
            // If max1 at this level is the depth of query node `q`, use max2 for the answer
            // Otherwise, use max1. Adjust by adding `level - 1` to the answer.
            queries[i] = (max1[level] == depth[q] ? max2[level] : max1[level]) + level - 1;
        }

        // Return the modified queries as answers
        return queries;
    }
};
/*
Time Complexity: O(n + q)
Space Complexity: O(n)
*/
