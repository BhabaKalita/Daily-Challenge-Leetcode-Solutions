class Solution {
public:
    // Function to get the mapped value of a given number using the mapping array
    int getVal(int num, vector<int>& mapping) {
        int mappedNum = 0;
        int placeVal = 1;

        // If the number is a single digit, directly return its mapped value
        if (num < 10)
            return mapping[num];

        // Process each digit of the number
        while (num) {
            int lastDigi = num % 10;       // Extract the last digit
            int mappedDigi = mapping[lastDigi];  // Get the mapped value of the last digit

            // Add the mapped digit to the mapped number considering its place value
            mappedNum += (mappedDigi * placeVal);
            placeVal *= 10;  // Update the place value for the next digit
            num /= 10;  // Remove the last digit from the number
        }

        return mappedNum;  // Return the mapped number
    }

    // Function to sort the given numbers according to their mapped values
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;  // Vector to store mapped values and their original indices

        // Iterate through each number in the nums array
        for (int i = 0; i < n; i++) {
            int mappedVal = getVal(nums[i], mapping);  // Get the mapped value of the current number

            vec.push_back({mappedVal, i});  // Store the mapped value and the original index

        }

        sort(vec.begin(), vec.end());  // Sort the vector based on mapped values

        vector<int> res;  // Result vector to store the sorted numbers

        // Collect the original numbers in the sorted order of their mapped values
        for (auto &x : vec) {
            int ind = x.second;  // Get the original index
            res.push_back(nums[ind]);  // Add the original number to the result
        }

        return res;  // Return the sorted array
    }
};
// Time Complexity: O(nlogn)
// Space Complexity: O(n)