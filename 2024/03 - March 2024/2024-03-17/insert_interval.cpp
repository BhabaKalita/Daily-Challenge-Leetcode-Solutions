class Solution {
public:
    // Function to insert a new interval into a set of non-overlapping intervals
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Result vector to store the merged intervals
        vector<vector<int>> res;

        // Iterate through each interval in the given set
        for (const auto& interval : intervals) {
            // Case 1: Current interval ends before the new interval starts
            if (interval[1] < newInterval[0]) {
                res.push_back(interval);
            }
            // Case 2: New interval ends before the current interval starts
            else if (newInterval[1] < interval[0]) {
                // Add the new interval to the result and update newInterval
                res.push_back(newInterval);
                newInterval = interval;
            }
            // Case 3: Overlapping intervals, merge them
            else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        // Add the final merged or remaining newInterval to the result
        res.push_back(newInterval);

        // Return the result vector containing merged intervals
        return res;
    }
};

// Time Complexity Analysis:
// The time complexity of the insert function is O(N), where N is the number of intervals.

// Space Complexity Analysis:
// The space complexity is O(1) since the input intervals are modified in-place, and the result vector is the only additional space used.