#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Create an unordered map to store the count of each element in the vector
        unordered_map<int, int> count;
        int res = 0;

        // Count occurrences of each element in the vector
        for (auto x : nums)
            count[x]++;

        // Iterate over the counts in the map
        for (auto& [_, y] : count) {
            // If an element occurs only once, return -1 as it's not possible to achieve the required operations
            if (y == 1)
                return -1;

            // Calculate the number of operations required for each element
            res += y / 3;

            // If there's a remainder, increment the operations count by 1
            if (y % 3)
                res++;
        }

        // Return the total operations count
        return res;
    }
};
/*
Time Compleixty: O(n)
Space Complexity: O(n)
*/
