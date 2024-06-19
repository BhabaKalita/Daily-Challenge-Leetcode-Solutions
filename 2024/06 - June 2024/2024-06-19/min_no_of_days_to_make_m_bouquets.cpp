class Solution {
public:
    int minDays(vector<int>& A, int m, int k) {
        int n = A.size();
        int left = 1, right = 1e9;

        // If the total number of flowers needed (m * k) is more than available flowers (n), return -1
        if ((long)m * k > n) return -1;

        // Binary search to find the minimum number of days
        while (left < right) {
            int mid = (left + right) / 2; // Calculate the middle point
            int flow = 0, bouq = 0; // Initialize the current flow length and bouquet count

            // Iterate through the flowers to count bouquets we can make by day `mid`
            for (int j = 0; j < n; ++j) {
                if (A[j] > mid) {
                    // If the flower at day `j` is not bloomed by `mid` days, reset the flow length
                    flow = 0;
                } else if (++flow >= k) {
                    // If we have `k` consecutive bloomed flowers, form a bouquet
                    bouq++;
                    flow = 0; // Reset the flow length after making a bouquet
                }
            }

            // If we can form fewer than `m` bouquets, we need more days
            if (bouq < m) {
                left = mid + 1;
            } else {
                // Otherwise, we try to find a smaller number of days
                right = mid;
            }
        }

        return left; // This will be the minimum number of days to form `m` bouquets
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/