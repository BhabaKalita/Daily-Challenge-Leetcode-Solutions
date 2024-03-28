class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
    // Initialize a map to count occurrences of elements in the subarray
    unordered_map<int, int> count;
    // Initialize variables
    int res = 0, i = 0, n = nums.size();
    // Loop through the array
    for (int j = 0; j < n; ++j) {
        // Increment the count of the current element
        count[nums[j]]++;
        // While the count of any element exceeds k, remove elements from the beginning of the subarray
        while (count[nums[j]] > k)
            count[nums[i++]]--;
        // Update the maximum subarray length
        res = max(res, j - i + 1);
    }
    return res;
    }
};

/*
Time Complexity : O(n)
Space Complexity : O(n)
*/