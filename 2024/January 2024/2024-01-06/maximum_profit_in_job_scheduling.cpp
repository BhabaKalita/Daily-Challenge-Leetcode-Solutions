#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        // Create a vector of jobs, each represented as {end time, start time, profit}
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }

        // Sort jobs based on end times
        sort(jobs.begin(), jobs.end());

        // Dynamic programming map to store maximum profit at each end time
        map<int, int> dp = {{0, 0}};

        // Iterate through sorted jobs
        for (auto& job : jobs) {
            // Find the job with the latest end time that doesn't overlap with the current job
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];

            // Update the maximum profit at the current end time
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }

        // Return the maximum profit achieved
        return dp.rbegin()->second;
    }
};

/*
Time Cimplexity: O(nlogn)
Space Complexity: O(n)
*/
