class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();  // Get the number of people
        unordered_map<int, string> mapping;  // Create a hash map to store the mapping of height to name

        // Populate the hash map with height as key and name as value
        for(int i = 0; i < n; i++) {
            mapping[heights[i]] = names[i];
        }

        // Sort the heights in descending order
        sort(heights.rbegin(), heights.rend());

        // Reorder names based on the sorted heights
        for(int j = 0; j < n; j++) {
            names[j] = mapping[heights[j]];
        }

        return names;  // Return the reordered names
    }
};
// Time Complexity: O(nlog(n))
// Space Complexity: O(n)