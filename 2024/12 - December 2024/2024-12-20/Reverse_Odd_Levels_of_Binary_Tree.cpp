class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> values;
        queue<TreeNode*> q;
        int level = 0;

        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;

            for(int i=0; i<sz; i++) {
                TreeNode* curr = q.front();
                q.pop();
                // temp.push_back(curr->val);

                if(level % 2) {
                    curr->val = values[sz-i-1];
                }

                if(curr->left) {
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                }
                if(curr->right) {
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }
            }
            values = temp;
            level++;

        }
        return root;
    }
};
