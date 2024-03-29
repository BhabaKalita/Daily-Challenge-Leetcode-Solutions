#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, cur = 0;
        long long res = 0;
        // Find the maximum element in the array
        int a = *max_element(nums.begin(), nums.end());

        // Iterate through the array
        for(int j = 0; j < n; j++) {
            // Increment the current count if the current element equals the maximum element
            cur += nums[j] == a;

            // While the current count is greater than or equal to k,
            // decrement the current count by removing elements from the beginning of the subarray
            while(cur >= k)
                cur -= nums[i++] == a;

            // Add the number of subarrays ending at the current index to the result
            res += i;
        }

        return res;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/