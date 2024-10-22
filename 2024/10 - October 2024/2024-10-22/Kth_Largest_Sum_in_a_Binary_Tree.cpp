class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Min-heap to store the top k largest sums
        priority_queue<long long, vector<long long>, greater<>> pq;
        // Call bfs with a reference to the priority queue
        bfs(root, pq, k);
        // If the priority queue has fewer than k elements, return -1
        return (pq.size() < k) ? -1 : pq.top();
    }
    
    // Pass the priority queue by reference
    void bfs(TreeNode* root, priority_queue<long long, vector<long long>, greater<>>& pq, int k) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* ele = q.front();
                q.pop();

                sum += ele->val;
                if (ele->left) q.push(ele->left);
                if (ele->right) q.push(ele->right);
            }
            
            pq.push(sum);
            // Keep only the top k largest sums in the priority queue
            if (pq.size() > k)
                pq.pop();
        }
    }
};
// Time Complexity : O(n+L⋅logk)
// Space Complexity : O(n+k)
