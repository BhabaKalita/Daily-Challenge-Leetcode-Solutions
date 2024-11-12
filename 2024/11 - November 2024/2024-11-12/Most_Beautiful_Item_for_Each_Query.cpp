class Solution {
public:
    // Function to find maximum beauty for each query
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Set an arbitrarily high value for comparison purposes
        int maxI = INT_MAX;

        // Initialize a result vector 'res' with a single entry:
        // {price = 0, beauty = 0, max_price_limit = maxI}
        vector<vector<int>> res = {{0, 0, maxI}};

        // Sort items by price in ascending order to process them in a logical sequence
        sort(items.begin(), items.end());

        // Traverse each item in the sorted list
        for (const auto& item : items) {
            int price = item[0];     // Current item's price
            int beauty = item[1];    // Current item's beauty score

            // If this item's beauty is greater than the last added beauty in 'res'
            if (beauty > res.back()[1]) {
                res.back()[2] = price;   // Update the last entry's max price limit to this item's price
                res.push_back({price, beauty, maxI}); // Add this item as a new entry in 'res'
            }
        }

        // Vector to store the final answers for each query
        vector<int> ans;

        // Process each query to determine the maximum beauty for each price limit in 'queries'
        for (int x : queries) {
            // Traverse 'res' in reverse to find the highest beauty within the query price 'x'
            for (int i = res.size() - 1; i >= 0; i--) {
                // Check if this entry's price is within the query limit
                if (res[i][0] <= x) {
                    ans.push_back(res[i][1]); // Add the corresponding beauty value to the result
                    break; // Move to the next query after finding the maximum beauty
                }
            }
        }

        return ans; // Return the answer vector containing maximum beauty for each query
    }
};
// Time Complexity : O(nlogn+q⋅n)
// Space Complexity : O(n+q)
