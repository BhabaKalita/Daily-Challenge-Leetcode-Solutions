class MyCalendarTwo {
private:
    // Map to store the number of bookings that start or end at a given time.
    map<int, int> mp;

public:
    MyCalendarTwo() {
        // Constructor, no initialization needed.
    }

    bool book(int start, int end) {
        // Increase the count of bookings starting at 'start'.
        mp[start]++;

        // Decrease the count of bookings ending at 'end'.
        mp[end]--;

        int sum = 0;

        // Iterate over the map entries.
        for (auto it = mp.begin(); it != mp.end(); it++) {
            // Add the current entry's value to the sum.
            sum += it->second;

            // If the sum exceeds 2, it means there are 3 or more overlapping bookings.
            if (sum >= 3) {
                // Undo the previous changes to the map.
                mp[start]--;
                mp[end]++;
                return false; // Booking is not possible due to overlapping.
            }
        }

        // If no overlapping found, the booking is possible.
        return true;
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(n)
*/
