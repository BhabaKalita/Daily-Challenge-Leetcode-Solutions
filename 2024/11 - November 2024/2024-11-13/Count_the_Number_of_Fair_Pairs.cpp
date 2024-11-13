class Solution {
public:
    // Function to count "fair" pairs (i, j) such that:
    // lower <= v[i] + v[j] <= upper and i < j
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        long long ans = 0;  // Initialize the count of fair pairs to zero

        // Sort the array to allow for binary search usage on the sorted pairs
        sort(v.begin(), v.end());

        // Iterate through each element in the sorted array
        for (int i = 0; i < v.size() - 1; i++) {
            // Find the first element in the range (i+1 to end) where v[i] + v[j] > upper
            auto up = upper_bound(v.begin() + i + 1, v.end(), upper - v[i]);

            // Find the first element in the range (i+1 to end) where v[i] + v[j] >= lower
            auto low = lower_bound(v.begin() + i + 1, v.end(), lower - v[i]);

            // The number of elements in the range [low, up) gives the count of valid pairs
            // for the current v[i] that satisfy the condition lower <= v[i] + v[j] <= upper
            ans += (up - low);
        }

        return ans;  // Return the total count of fair pairs
    }
};
//Time Complexity : O(nlogn)
//Space Complexity : O(1)
