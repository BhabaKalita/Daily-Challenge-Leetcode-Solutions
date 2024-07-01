class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0; // Initialize a counter to keep track of consecutive odd numbers

        for(int x : arr) { // Iterate through each element in the array
            if(x % 2 != 0) { // Check if the current element is odd
                count++; // Increment the counter if the element is odd

                if(count == 3) // If there are three consecutive odd numbers
                    return true; // Return true
            } else {
                count = 0; // Reset the counter if the current element is even
            }
        }
        return false; // Return false if no three consecutive odd numbers are found
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)