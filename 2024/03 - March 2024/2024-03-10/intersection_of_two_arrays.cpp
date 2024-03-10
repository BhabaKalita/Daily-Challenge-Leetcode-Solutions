#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Create an unordered set 's' containing elements from nums1
        unordered_set<int> s(nums1.begin(), nums1.end());

        // Initialize a vector to store the intersection
        vector<int> res;

        // Iterate through elements of nums2
        for (int x : nums2) {
            // If element x is found in 's', erase it from 's' and add it to the result vector
            if (s.erase(x)) {
                res.push_back(x);
            }
        }

        // Return the vector containing the intersection
        return res;
    }
};

/*
Time Complexity: O(m + n)
Space Complexity: O(n)
*/