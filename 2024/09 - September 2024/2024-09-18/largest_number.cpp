bool compare(int a, int b) {
    // Convert integers to strings for comparison.
    string sa = to_string(a);
    string sb = to_string(b);

    // Compare concatenated strings to determine the larger number.
    if ((sa + sb) > (sb + sa)) {
        return true;
    } else {
        return false;
    }
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Sort the numbers using the custom comparison function.
        sort(nums.begin(), nums.end(), compare);

        // Check if the largest number is 0 to avoid leading zeros.
        if (nums[0] == 0) {
            return "0";
        }

        // Concatenate the sorted numbers into a string.
        string ans = "";
        for (auto& x : nums) {
            ans += to_string(x);
        }

        // Return the concatenated string.
        return ans;
    }
};
/*
  Time Complexity : O(nlogn)
  Space Complexity : O(n)
*/
