class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Create an unordered map to store the frequency of each task
        unordered_map<char, int> mp;

        // Variable to track the maximum frequency of any task
        int count = 0;

        // Iterate through each task
        for (auto e : tasks) {
            // Increment the frequency of the task
            mp[e]++;

            // Update the maximum frequency
            count = max(count, mp[e]);
        }

        // Calculate the number of intervals based on the task with the maximum frequency
        int ans = (count - 1) * (n + 1);

        // Iterate through the map to find tasks with frequency equal to the maximum count
        for (auto e : mp) {
            if (e.second == count) {
                // Increment the answer for each task with the maximum frequency
                ans++;
            }
        }

        // The final answer is the maximum between the total number of tasks and the calculated intervals
        return max((int)tasks.size(), ans);
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N)