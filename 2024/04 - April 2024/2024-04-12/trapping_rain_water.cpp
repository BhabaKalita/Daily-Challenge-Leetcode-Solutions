class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n), right_max(n); // Arrays to store the maximum height on the left and right side of each element
        int res = 0; // Initialize the result

        // Calculate the maximum height to the left of each element
        int maxiL = height[0]; // Initialize maxiL to the height of the first element
        for(int i = 0; i < n; i++) {
            left_max[i] = max(height[i], maxiL); // Store the maximum of the current height and maxiL in left_max

            maxiL = max(maxiL, height[i]); // Update maxiL if the current height is greater
        }

        // Calculate the maximum height to the right of each element
        int maxiR = height[n-1]; // Initialize maxiR to the height of the last element
        for(int j = n - 1; j >= 0; j--) {
            right_max[j] = max(height[j], maxiR); // Store the maximum of the current height and maxiR in right_max

            maxiR = max(maxiR, height[j]); // Update maxiR if the current height is greater
        }

        // Calculate the trapped water for each element and add it to the result
        for(int k = 0; k < n; k++) {
            res += min(left_max[k], right_max[k]) - height[k]; // Add the trapped water for the current element to res
        }

        return res; // Return the total trapped water
    }
};

/*
Time Complexity : O(n)
Space Complexity : O(n)
*/