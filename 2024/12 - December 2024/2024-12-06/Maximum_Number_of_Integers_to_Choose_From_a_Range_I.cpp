class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Convert the banned list into an unordered_set for fast lookup
        unordered_set<int> ban(banned.begin(), banned.end());

        int sum = 0;   // Variable to keep track of the cumulative sum
        int count = 0; // Variable to count the valid numbers

        // Iterate through numbers from 1 to n
        for(int i = 1; i <= n; i++) {
            // If the number is in the banned list, skip it
            if(ban.count(i) != 0) continue;

            // Add the number to the cumulative sum
            sum += i;

            // If the cumulative sum exceeds maxSum, stop the loop
            if(sum > maxSum) break;

            // Increment the count of valid numbers
            count++;
        }
        return count; // Return the count of valid numbers
    }
};
// Time Complexity: O(b+n)
// Space Complexity: O(b)
