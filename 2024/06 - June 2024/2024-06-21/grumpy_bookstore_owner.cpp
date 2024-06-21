class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // Variable to store the initial satisfaction without considering the grumpy periods.
        int initialSatisfaction = 0;

        // Variable to store the maximum extra satisfaction we can get by making the owner not grumpy.
        int maxExtraSatisfaction = 0;

        // Variable to store the extra satisfaction in the current window of 'minutes' length.
        int currentWindowSatisfaction = 0;

        // Loop through the customers array to calculate the initial satisfaction and the first window of extra satisfaction.
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                // If the owner is not grumpy, add the number of customers directly to initial satisfaction.
                initialSatisfaction += customers[i];
            } else if (i < minutes) {
                // If the owner is grumpy and within the first 'minutes' window, add to the current window satisfaction.
                currentWindowSatisfaction += customers[i];
            }
        }

        // Set the initial maximum extra satisfaction to the current window satisfaction.
        maxExtraSatisfaction = currentWindowSatisfaction;

        // Slide the window across the rest of the array.
        for (int i = minutes; i < customers.size(); ++i) {
            // Add the new element in the window if the owner is grumpy.
            currentWindowSatisfaction += customers[i] * grumpy[i];

            // Remove the element that is no longer in the window if the owner was grumpy.
            currentWindowSatisfaction -= customers[i - minutes] * grumpy[i - minutes];

            // Update the maximum extra satisfaction if the current window has more extra satisfaction.
            maxExtraSatisfaction = max(maxExtraSatisfaction, currentWindowSatisfaction);
        }

        // The result is the sum of initial satisfaction and the maximum extra satisfaction we can gain.
        return initialSatisfaction + maxExtraSatisfaction;   
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)