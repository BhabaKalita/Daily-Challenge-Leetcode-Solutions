#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // Priority queue to store the height differences
        priority_queue<int> pq;

        // Loop through the buildings
        for(int i = 0; i < heights.size() - 1; i++) {
            // Calculate the height difference between current and next building
            int d = heights[i + 1] - heights[i];

            // If the difference is positive, it means bricks are needed
            if(d > 0) {
                pq.push(-d); // Store negative of the difference to simulate a min heap
            }

            // If the number of differences stored exceeds the number of ladders available
            if(pq.size() > ladders) {
                // Use bricks to cover the difference of the smallest height increase
                bricks += pq.top();
                pq.pop();
            }

            // If bricks run out, return the index of the last building that can be reached
            if(bricks < 0) {
                return i;
            }
        }
        // If all buildings can be reached
        return heights.size() - 1;
    }
};

/*
Time Complexity: O(n log k)
Space Complexity: O(k)
*/