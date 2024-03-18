#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Initialize count to keep track of arrows needed
        int count = 0;
        // Initialize arrow position
        int arrow = 0;

        // Sort points based on the starting point
        sort(points.begin(), points.end());

        // Iterate through each balloon interval
        for (auto arr : points) {
            // If it's the first balloon or the starting point of the current balloon is beyond the arrow position
            if (count == 0 || arr[0] > arrow) {
                // Increment the count as a new arrow is needed
                count++;
                // Update arrow position to the end of the current balloon
                arrow = arr[1];
            } else {
                // If the starting point of the current balloon is within the arrow range
                // Update the arrow position to the minimum of current arrow and the end of the current balloon
                arrow = min(arrow, arr[1]);
            }
        }

        // Return the total count of arrows needed
        return count;
    }
};

/*
Time Complexity: O(N log N)
Space Complexity: O(1)
*/