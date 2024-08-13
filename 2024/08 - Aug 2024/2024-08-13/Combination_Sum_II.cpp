class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the candidates to handle duplicates and make the logic for combinations easier
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; // Vector to store the final list of combinations
        vector<int> ds; // Temporary vector to store the current combination
        findCombination(0, target, candidates, ans, ds); // Call the recursive function
        return ans; // Return the final result
    }

    void findCombination(int s, int target, vector<int>& candidates, vector<vector<int>> &ans, vector<int> &ds) {
        // If the target becomes 0, we have found a valid combination
        if(target == 0) {
            ans.push_back(ds); // Add the current combination to the result list
            return;
        }

        // Loop through the candidates starting from the index 's'
        for(int i = s; i < candidates.size(); i++) {
            // Skip duplicates to avoid repeating the same combination
            if(i > s && candidates[i] == candidates[i-1]) continue;

            // If the current candidate exceeds the target, break out of the loop (further elements will also be too large)
            if(candidates[i] > target) break;

            // Include the current candidate in the combination
            ds.push_back(candidates[i]);
            // Recursively call findCombination with the next index and the updated target
            findCombination(i+1, target-candidates[i], candidates, ans, ds);
            // Backtrack: remove the last added candidate to try the next possibility
            ds.pop_back();
        }
    }
};
// Time Complexity: O(2^n)
// Space Complexity: O(n)