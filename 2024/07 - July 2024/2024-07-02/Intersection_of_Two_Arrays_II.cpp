class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Sort both input arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0; // Initialize two pointers
        vector<int> result; // Vector to store the intersection

        // Use two-pointer technique to find common elements
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++; // Move pointer i if current element of nums1 is smaller
            } else if (nums1[i] > nums2[j]) {
                j++; // Move pointer j if current element of nums2 is smaller
            } else {
                result.push_back(nums1[i]); // Elements are equal, add to result
                i++; // Move both pointers
                j++;
            }
        }

        return result; // Return the intersection result
    }
};
// Time Complexity: O(nlogn+mlogm)
// Space Complexity: O(min(n,m))