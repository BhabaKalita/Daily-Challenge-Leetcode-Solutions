#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Create a count array to keep track of the count of each element
        vector<int> count(nums.size() + 10);

        // Initialize the 2D vector to store grouped elements
        vector<vector<int>> res;

        // Iterate through each element in the input vector nums
        for (auto x : nums) {
            // Check if there are enough rows in res to accommodate the current count
            if (res.size() <= count[x])
                res.push_back({});

            // Add the current element to the corresponding row and increment its count
            res[count[x]++].push_back(x);
        }

        return res;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
