class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Create an unordered map to store the length of the square streak for each number
        unordered_map<int, int> mp;

        // Sort the array in ascending order to efficiently check for square roots
        sort(nums.begin(), nums.end());

        // Initialize the maximum length of a square streak found so far
        int maxi = 0;

        for (auto num : nums) {
            // Calculate the square root of the current number
            int root = (int)sqrt(num);

            // If the number is a perfect square and its square root is already in the map,
            // increment the streak length for the current number by 1
            if (root * root == num && mp.find(root) != mp.end()) {
                mp[num] = mp[root] + 1;
            } 
            // Otherwise, initialize the streak length for the current number to 1
            else {
                mp[num] = 1;
            }

            // Update the maximum streak length if necessary
            maxi = max(maxi, mp[num]);
        }

        // Return -1 if no square streak of length 2 or more is found, otherwise return the maximum length
        return maxi < 2 ? -1 : maxi;
    }
};
/*
  Time Complexity : O(N log N)
  Space Complexity : O(N)
*/
