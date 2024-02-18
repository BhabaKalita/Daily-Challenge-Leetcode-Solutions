#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Priority queue to keep track of rooms' availability, sorted by the end time of meetings
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        // Array to keep track of the number of bookings for each room
        int cnt[101] = {};

        // Sort meetings based on start time
        sort(begin(meetings), end(meetings));

        // Initialize the priority queue with initial meetings for each room
        for(int i = 0; i < n; i++)
            pq.push({meetings[0][0], i});

        // Process each meeting
        for(auto &m: meetings) {
            // Update room availability until the current meeting's start time
            while(pq.top().first < m[0]) {
                pq.push({m[0], pq.top().second});
                pq.pop();
            }

            // Extract the next available room and its start time
            auto [start, room] = pq.top();

            // Calculate the end time of the current meeting and update room availability
            pq.push({start + m[1] - m[0], room});
            ++cnt[room];

            // Remove the room from availability after booking
            pq.pop();
        }

        // Find the room with the maximum number of bookings
        return max_element(begin(cnt), end(cnt)) - begin(cnt);
    }
};
