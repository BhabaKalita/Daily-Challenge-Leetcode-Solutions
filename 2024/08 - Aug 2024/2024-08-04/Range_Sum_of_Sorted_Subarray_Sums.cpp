class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;

        // Generate all possible subarray sums
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = i; j < n; j++) {
                count += nums[j];
                arr.push_back(count);
            }
        }

        // Sort the subarray sums
        sort(arr.begin(), arr.end());

        // Calculate the sum of elements from index 'left' to 'right' (1-based index)
        int MOD = 1000000007;
        int res = 0;
        for(int x = left - 1; x < right; x++) {
            res = (res + arr[x]) % MOD;
        }

        return res;
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)