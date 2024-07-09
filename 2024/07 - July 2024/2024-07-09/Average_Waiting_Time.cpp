class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size(); // Get the number of customers

        double totalWaitTime = 0; // Initialize total waiting time to 0
        int currTime = 0;         // Initialize current time to 0

        // Loop through each customer
        for(auto &vec : customers) {
            int arrivalTime = vec[0]; // Customer's arrival time
            int cookTime = vec[1];    // Time taken to prepare the food

            // If the current time is less than the arrival time, update the current time to the arrival time
            if(currTime < arrivalTime)
                currTime = arrivalTime;

            // Calculate the wait time for the current customer
            int waitTime = currTime + cookTime - arrivalTime;

            // Add the current customer's wait time to the total waiting time
            totalWaitTime += waitTime;

            // Update the current time after the food is cooked
            currTime += cookTime;
        }

        // Calculate and return the average waiting time
        return totalWaitTime / n;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)