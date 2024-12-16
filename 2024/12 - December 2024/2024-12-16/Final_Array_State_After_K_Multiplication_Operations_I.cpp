class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        int n = nums.size();

        while(k--) {
            int idx = 0, ans = nums[0];

            for(int i=1; i<n; i++) {

                if(nums[i] < ans) {
                    ans = nums[i];
                    idx = i;
                }
            }
            nums[idx] = nums[idx] * multiplier;
        }

        return nums;
    }
};
// Time Complexity : O(N*K)
// Space Complexity : O(1)
