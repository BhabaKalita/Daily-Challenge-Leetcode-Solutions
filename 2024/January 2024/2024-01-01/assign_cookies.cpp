#include <vector>
#include <algorithm>git stT

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Initialize two pointers, i for the children's greed factor and j for the available cookies
        int i = 0, j = 0;

        // Sort the arrays in ascending order
        sort(begin(g), end(g));
        sort(s.begin(), s.end());

        // Iterate through the arrays until either one of them is exhausted
        while (i < g.size() and j < s.size()) {
            // Check if the current cookie size is sufficient for the current child's greed
            if (s[j] >= g[i])
                i++; // Move to the next child
            j++; // Move to the next available cookie
        }

        // The value of i represents the number of content children
        return i;
    }
};

// Time Complexity: O(nlogn + mlogm), where n is the size of vector g and m is the size of vector s.
// The dominant factor is the sorting operation.
// Space Complexity: O(1), as no extra space is used except for a constant number of variables.
