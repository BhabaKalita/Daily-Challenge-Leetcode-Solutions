class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Create an unordered_set to store the numbers we have seen so far
        unordered_set<int> seen;

        // Loop through each number in the input array
        for (int num : arr) {
            // Check if either twice the current number or half the current number (if it's even) exists in the set
            if (seen.count(num * 2) || (num % 2 == 0 && seen.count(num / 2))) {
                return true; // If such a number exists, return true
            }

            // Add the current number to the set
            seen.insert(num);
        }

        // If no such pair is found after the loop, return false
        return false;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
