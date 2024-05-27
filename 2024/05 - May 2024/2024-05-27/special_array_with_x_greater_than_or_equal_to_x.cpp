class Solution {
public:
    int specialArray(vector<int>& nums) {
        // Initialize the count array to zero and get the size of nums
        int count[102] = { 0 }, N = nums.size();

        // Count occurrences of each number in nums, capped at N
        for (int n : nums) {
            count[min(n, N)]++;
        }

        // Accumulate counts from the end of the array
        for (int i = N; i >= 0; i--) {
            count[i] = count[i + 1] + count[i];
            // Check if the current count equals the index
            if (count[i] == i) {
                return i;
            }
        }

        // Return -1 if no such number is found
        return -1;
    }
};

/*
Time Complexity:
- The first loop iterates over each element in nums to populate the count array. This takes O(N) time, where N is the number of elements in nums.
- The second loop runs from N down to 0, updating the count array and checking the condition. This takes O(N) time.
- Therefore, the overall time complexity is O(N).

Space Complexity:
- The space complexity is dominated by the count array of size 102, which is a constant size.
- Therefore, the overall space complexity is O(1) as it does not depend on the input size.
*/
