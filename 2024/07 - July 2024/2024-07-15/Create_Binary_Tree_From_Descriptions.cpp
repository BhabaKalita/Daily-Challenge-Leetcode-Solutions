class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp; // map to store node references by their values
        unordered_set<int> childSet; // set to store all child node values

        // Loop through each description
        for(auto &val : descriptions) {
            int parent = val[0];
            int child = val[1];
            int isLeft = val[2];

            // Create parent node if it doesn't exist in the map
            if(mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            // Create child node if it doesn't exist in the map
            if(mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            // Link child node to parent node on the appropriate side
            if(isLeft == 1) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            // Add child node value to the child set
            childSet.insert(child);
        }

        // Find the root node (which is not a child of any node)
        for(auto &root : descriptions) {
            int parent = root[0];
            if(childSet.find(parent) == childSet.end()) {
                return mp[parent];
            }
        }

        // If no root node is found, return NULL
        return NULL;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)