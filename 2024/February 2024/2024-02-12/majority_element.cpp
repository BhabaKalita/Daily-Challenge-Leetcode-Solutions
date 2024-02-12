#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Initialize the candidate element as the first element in the array
        int candidate = nums[0];
        // Initialize the count of the candidate element
        int count = 1;

        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If count becomes 0, update the candidate to the current element
            if (count == 0) {
                candidate = nums[i];
                count++;
            } 
            // If the current element is the same as the candidate, increment the count
            else if (candidate == nums[i]) {
                count++;
            } 
            // If the current element is different from the candidate, decrement the count
            else {
                count--;
            }
        }
        // The candidate at the end will be the majority element
        return candidate;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/