class Solution {
public:
    // Helper function to check if it's possible to distribute items
    // so that the maximum quantity in any store is no more than 'mid'
    bool distr(int mid, vector<int>& q, int n) {
        // Loop over each quantity in the `q` vector
        for (auto x : q) {
            // Calculate how many stores are needed to distribute 'x' items 
            // so that no store receives more than 'mid' items
            n -= (x + mid - 1) / mid;

            // If we need more stores than available, return false
            if (n < 0)
                return false;
        }

        // If we can distribute within 'n' stores, return true
        return true;
    }

    // Main function to find the minimized maximum quantity in any store
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();  // Number of different types of items

        int l = 1;  // Minimum possible value for the max quantity in any store
        int r = *max_element(begin(quantities), end(quantities)); // Max quantity of any single item
        int res = 0;  // Variable to store the final result

        // Perform binary search on the possible values of max quantity per store
        while (l <= r) {
            int mid = l + (r - l) / 2; // Calculate the midpoint of the current range

            // Check if we can distribute items such that no store has more than 'mid' items
            if (distr(mid, quantities, n)) {
                res = mid; // Update result as we found a feasible distribution with max = 'mid'
                r = mid - 1; // Try to find a smaller feasible max quantity
            } else {
                l = mid + 1; // Increase the minimum bound to look for a larger feasible max
            }
        }

        return res; // Return the minimized maximum quantity per store
    }
};
// Time Complexity : O(mlog(max(quantities)))
// Space Complexity : O(1)
