#include <vector>
#include <algorithm>
using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    vector<pair<int, int>> jobs;  // Vector to hold pairs of difficulty and profit.
    int N = profit.size();  // Number of jobs available.
    int res = 0;  // Variable to store the total maximum profit.
    int i = 0;  // Index to iterate through the sorted jobs.
    int best = 0;  // Variable to track the best (maximum) profit achievable with current worker's ability.

    // Pair up difficulties and profits and push them into the jobs vector.
    for (int j = 0; j < N; ++j)
        jobs.push_back(make_pair(difficulty[j], profit[j]));

    // Sort the jobs vector based on difficulty.
    sort(jobs.begin(), jobs.end());

    // Sort the worker vector based on their abilities.
    sort(worker.begin(), worker.end());

    // Iterate over each worker.
    for (int &ability : worker) {
        // Find the best job the worker can do without exceeding their ability.
        while (i < N && ability >= jobs[i].first)
            best = max(jobs[i++].second, best);

        // Add the best profit achievable with this worker to the total result.
        res += best;
    }

    // Return the total maximum profit.
    return res;
}
// Time Complexity: O(N log N + M log M)
// Space Complexity: O(N)