class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        // Initialize count variable to keep track of consecutive elements
        int count = 0;
        // Get the size of the input array
        int n = arr.size();

        // Iterate through the array
        for(int i = 0; i < n - 1; i++) {
            // Check if the current element is equal to the next one
            if (arr[i] == arr[i + 1])
                count++;
            else
                count = 1;  // Reset count if the current and next elements are not equal

            // Check if the consecutive count is greater than a quarter of the array size
            if (count > n / 4)
                return arr[i];  // Return the special integer if the condition is met
        }

        return arr[0];  // If no special integer is found, return the first element
    }
};

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/