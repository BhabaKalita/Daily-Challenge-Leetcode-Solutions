class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size(); // Get the number of friends

        // Create an array 'order' to store the indices of friends, i.e., 0 to n-1.
        vector<int> order(n);
        for (int i = 0; i < n; ++i) order[i] = i;

        // Sort 'order' based on the arrival times of each friend.
        sort(order.begin(), order.end(), [&times](int a, int b) {
            return times[a][0] < times[b][0]; // Sort by arrival time in ascending order.
        });

        // Min-heap (priority_queue) to track the smallest available (empty) seats.
        priority_queue<int, vector<int>, greater<int>> emptySeats;

        // Min-heap (priority_queue) to track seats that are currently taken.
        // Stores pairs of (leaving time, seat number).
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> takenSeats;

        // Initially, all seats from 0 to n-1 are empty, so push them into the emptySeats heap.
        for (int i = 0; i < n; ++i) emptySeats.push(i);

        // Iterate over each friend's index based on their arrival order
        for (int i : order) {
            int arrival = times[i][0];  // Get the arrival time of the current friend
            int leave = times[i][1];    // Get the leaving time of the current friend

            // Free up seats that are available because friends have left before or exactly at 'arrival' time.
            while (!takenSeats.empty() && takenSeats.top().first <= arrival) {
                emptySeats.push(takenSeats.top().second);  // Push the freed seat into emptySeats heap.
                takenSeats.pop();  // Remove the top from takenSeats since this friend has left.
            }

            // The top of the emptySeats heap gives us the smallest available seat.
            int seat = emptySeats.top();
            emptySeats.pop(); // Mark this seat as taken (remove from available seats).

            // If the current friend is the targetFriend, return the seat number.
            if (i == targetFriend) return seat;

            // Mark the seat as taken by pushing it into takenSeats with the friend's leaving time.
            takenSeats.push({leave, seat});
        }

        return -1;  // This should never be reached, but added to avoid compilation warnings.
    }
};
/*
  Time Complexity: O(n log n)
  Space Complexity: O(n)
*/
