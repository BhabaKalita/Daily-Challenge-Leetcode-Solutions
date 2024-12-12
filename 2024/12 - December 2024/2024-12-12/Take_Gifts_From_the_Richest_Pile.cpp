class Solution {
public:
#define ll long long
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(),gifts.end());

        while(k--) {
            int top = maxHeap.top();
            maxHeap.pop();

            maxHeap.push(sqrt(top));
        }

        ll sum = 0;
        while(!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};
// Time Complexity : O((n+k)logn)
// Space Complexity : O(n)
