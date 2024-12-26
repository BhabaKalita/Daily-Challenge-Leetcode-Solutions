class Solution {
    // Memoization map to store intermediate results: key is a string (position * sum), value is the result
    unordered_map<string, int> mem;

    // Recursive function to compute the number of ways
    long long ways(vector<int>& nums, int n, int sum, int S, int pos) {
        // Base case: If we've reached the last element (pos == n)
        if (n == pos)
            // If the sum equals the target S, return 1 (found a valid way), otherwise return 0
            return sum == S ? 1 : 0;

        // Create a unique key for the current state (position * sum) to store in the memoization map
        string key = to_string(pos) + "*" + to_string(sum);

        // If this state has already been computed, return the stored result from the memoization map
        if (mem.find(key) != mem.end())
            return mem[key];

        // Recursively compute the number of ways by including both + and - signs for the current number
        // Store the result in the memoization map to avoid redundant calculations
        return mem[key] = ways(nums, n, sum + nums[pos], S, pos + 1) 
                         + ways(nums, n, sum - nums[pos], S, pos + 1);
    }

public:
    // Main function to find the number of ways to assign + or - to elements of nums to reach target S
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();  // Get the size of the input array
        if (n == 0)  // If the input array is empty, return 0 as there are no ways
            return 0;

        // Start recursion from the second position with the first element being positive or negative
        return ways(nums, n, nums[0], S, 1) + ways(nums, n, -nums[0], S, 1);
    }
// };
// Time Complexity: O(n * sum_max)
// Space Complexity: O(n * sum_max)
