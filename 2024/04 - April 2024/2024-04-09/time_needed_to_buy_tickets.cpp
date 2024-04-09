class Solution {
public:
    // Function to calculate the time required to buy tickets
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0; // Initialize the time required to 0

        // Loop through each ticket
        for(int i = 0; i < tickets.size(); i++) {
            // If the price of the ticket is less than the price of ticket at index k
            if(tickets[i] < tickets[k]) 
                time += tickets[i]; // Add the price of this ticket to the total time
            else
                time += tickets[k]; // Otherwise, add the price of the ticket at index k

            // If the current ticket is after the kth ticket and its price is greater than or equal to the kth ticket
            if(i > k && tickets[i] >= tickets[k]) 
                time--; // Subtract one from the total time
        }
        return time; // Return the total time required
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/