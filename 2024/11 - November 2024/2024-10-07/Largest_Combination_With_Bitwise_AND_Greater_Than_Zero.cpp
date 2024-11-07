class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // Step 1: Get the size of the input vector
        int n = candidates.size(), ans = 0; // Initialize `n` to size of candidates, and `ans` to 0 to track the result.

        // Step 2: Iterate over each bit position (0 through 31, assuming 32-bit integers)
        for(int i = 0; i < 32; i++){
            int cnt = 0; // Initialize a counter `cnt` to track how many numbers have a "1" at bit position `i`.

            // Step 3: Check each candidate number for a "1" at bit position `i`
            for(auto candidate : candidates){
                if(candidate & (1 << i)) // Check if the i-th bit is set to "1" in `candidate`
                    cnt++; // If so, increment the counter
            }

            // Step 4: Update `ans` to the maximum number of candidates sharing a "1" at any bit position so far
            ans = max(ans, cnt);
        }

        // Step 5: Return the result, which is the largest subset size for a bit position
        return ans;
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(1)
*/
