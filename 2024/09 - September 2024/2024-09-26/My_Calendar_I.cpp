class MyCalendar {
private:
    map<int, int> mp;  // Map to store start and end events of bookings
public:
    // Constructor to initialize the class
    MyCalendar() { 
    }
    
    // Function to attempt to book an event from 'start' to 'end'
    bool book(int start, int end) {
        int sum = 0;  // Variable to track the number of overlapping events

        // Increment the start point of the booking in the map (mark event start)
        mp[start]++;
        // Decrement the end point of the booking in the map (mark event end)
        mp[end]--;

        // Iterate over all events in the map (automatically sorted by time)
        for (auto i = mp.begin(); i != mp.end(); i++) {
            int val = i->second;  // Get the value (number of events starting or ending)
            sum += val;  // Add this value to the running sum

            // If at any point, the number of simultaneous events is greater than 1, it's an overlap
            if (sum > 1) {
                // Revert the changes made to the map for this booking, since it's invalid
                mp[start]--;
                mp[end]++;

                return false;  // Booking cannot be made due to overlap
            }
        }

        // If no overlap is found, the booking is successful
        return true;
    }
};
/*
  Time Complexity: O(n)
  Space Complexity: O(n)
*/
