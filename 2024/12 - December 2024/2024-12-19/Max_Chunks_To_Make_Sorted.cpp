class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), ch = 0, maxi = 0;
        for(int i=0; i<n; i++) {
            // if(i == n) return ch;
            maxi = max(maxi, arr[i]);
            if(i == maxi) ++ch;
        }
        return ch;
    }
};
//Time Complexity : O(n)
//Space Complexity : O(1)
