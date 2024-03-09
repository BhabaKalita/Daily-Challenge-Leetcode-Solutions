#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    // Function to find the common element between two sorted arrays
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Initialize pointers for both arrays
        int i = 0, j = 0;
        // Initialize result variable
        int res = INT_MAX;

        // Loop until either of the arrays reaches its end
        while (i < nums1.size() && j < nums2.size()) {
            // If current elements of both arrays are equal
            if (nums1[i] == nums2[j]) {
                // Update result and exit loop
                res = nums1[i];
                break;
            }
            // If element in nums1 is smaller, move pointer in nums1
            else if (nums1[i] < nums2[j]) {
                ++i;
            }
            // If element in nums2 is smaller, move pointer in nums2
            else {
                ++j;
            }
        }

        // If a common element is found, return it. Otherwise, return -1.
        return res != INT_MAX ? res : -1;
    }
};

/*
Time Complexity: O(m + n)
Space Complexity: O(1)
*/