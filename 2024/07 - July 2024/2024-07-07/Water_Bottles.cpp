class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Calculate the total number of bottles drunk directly plus the number of bottles that can be obtained through exchanges
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)