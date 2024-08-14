class Solution {
public:
    // Function to find the k-th smallest distance pair in a sorted array
    int smallestDistancePair(std::vector<int>& nums, int k) {
        // First, sort the input array to facilitate distance calculation
        std::sort(nums.begin(), nums.end());

        // Initialize binary search bounds
        int left = 0;  // Minimum possible distance
        int right = nums[nums.size() - 1] - nums[0];  // Maximum possible distance

        // Perform binary search to find the smallest distance pair
        while (left < right) {
            int mid = (left + right) / 2;  // Calculate middle point of current bounds

            // Check if there are at least k pairs with distance <= mid
            if (issmallpairs(nums, k, mid))
                right = mid;  // If true, narrow search to the left half
            else
                left = mid + 1;  // Otherwise, narrow search to the right half
        }
        // After the loop, left is the smallest distance pair that has at least k pairs
        return left;
    }

private:
    // Helper function to count pairs with distance <= mid
    bool issmallpairs(const std::vector<int>& nums, int k, int mid) {
        int count = 0, left = 0;  // Initialize count of valid pairs and left pointer

        // Iterate over the array with right pointer
        for (int right = 1; right < nums.size(); right++) {
            // Adjust left pointer until the distance is within the current mid threshold
            while (nums[right] - nums[left] > mid) left++;
            // Count all valid pairs (right - left gives number of valid pairs ending at right)
            count += right - left;
        }
        // Check if the number of pairs with distance <= mid is at least k
        return (count >= k);
    }
};
// Time Complexity: O(nlogn)
// Space Complexity: O(1)