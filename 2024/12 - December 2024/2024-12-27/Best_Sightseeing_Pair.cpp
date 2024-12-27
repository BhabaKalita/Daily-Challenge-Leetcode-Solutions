class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int cur = 0, res = 0;

        for(int x:values) {
            res = max(res, cur+x);
            cur = max(cur, x) - 1;
        }
        return res;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)
