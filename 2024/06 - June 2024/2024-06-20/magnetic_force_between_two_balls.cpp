class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        // Step 1: Sort the position vector
        sort(position.begin(), position.end());

        int n = position.size(); // Number of positions

        // Step 2: Initialize the binary search range
        int s = 1; // Start with the minimum possible distance (at least 1 unit apart)
        int e = position[n - 1] - position[0]; // End with the maximum possible distance
        int ans; // Variable to store the answer

        // Step 3: Perform binary search
        while (s <= e) {
            int mid = s + (e - s) / 2; // Midpoint of the current search range
            int count = 1; // We can always place the first ball
            int pos = position[0]; // Place the first ball at the first position

            // Step 4: Try to place the rest of the balls
            for (int i = 1; i < n; i++) {
                // Check if we can place a ball at position[i] with at least 'mid' distance from the last placed ball
                if (pos + mid <= position[i]) {
                    count++; // Increment the count of placed balls
                    pos = position[i]; // Update the position of the last placed ball
                }
            }

            // Step 5: Adjust the binary search range based on the count of placed balls
            if (count < m) {
                // If we can't place 'm' balls, reduce the search range
                e = mid - 1;
            } else {
                // If we can place 'm' or more balls, store 'mid' as a possible answer and search for a larger distance
                ans = mid;
                s = mid + 1;
            }
        }
        // Step 6: Return the maximum possible minimum distance
        return ans;
    }
};
/*
Time Complexity: O(nlog⁡n)
Space Complexity: O(n)
*/