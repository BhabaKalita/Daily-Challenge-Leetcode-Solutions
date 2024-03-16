#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, maxi = 0; // Initialize variables to keep track of the running sum and maximum length
        unordered_map<int, int> vis({{0,-1}}); // Initialize a map to store the running sum and its corresponding index

        for(int i=0; i<nums.size(); i++) {
            // Update the running sum based on the current element in nums
            sum += nums[i] == 1 ? 1 : -1;

            // If the current sum is encountered before, update the maximum length
            // by calculating the difference between the current index and the index
            // where the sum was previously encountered. Otherwise, store the sum
            // along with its index.
            if(vis.count(sum))
                maxi = max(maxi, i-vis[sum]);
            else
                vis[sum] = i;
        }
        return maxi; // Return the maximum length of contiguous subarray with equal number of 0s and 1s
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/