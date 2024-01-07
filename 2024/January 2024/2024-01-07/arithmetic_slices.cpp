#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;

        // dp[i][d] represents the number of arithmetic slices ending at index i with a common difference d
        vector<unordered_map<long long, int>> dp(n);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Calculate the difference between the elements at indices i and j
                long long diff = static_cast<long long>(nums[i]) - nums[j];

                // Retrieve the count of arithmetic slices with the common difference 'diff' ending at index j
                int cnt = dp[j].count(diff) ? dp[j][diff] : 0;

                // Update dp[i][diff] with the count of arithmetic slices ending at index i with common difference 'diff'
                dp[i][diff] += cnt + 1;

                // Update the total count of arithmetic slices
                ans += cnt;
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/
