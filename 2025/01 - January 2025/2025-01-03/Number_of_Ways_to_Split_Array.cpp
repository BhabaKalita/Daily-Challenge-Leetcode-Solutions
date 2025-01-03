class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Calculate the total sum of the array
        long long leftSum = 0, rightSum = 0; 
        for(int sum:nums)
            rightSum += sum;

        // Initialize a counter to track the number of valid splits
        int count = 0; 

        // Iterate through the array, excluding the last element
        for(int i=0; i<nums.size()-1; i++) { 
            // Update leftSum and rightSum for the current split
            leftSum += nums[i];
            rightSum -= nums[i];

            // Check if the current split satisfies the condition (leftSum >= rightSum)
            if(leftSum >= rightSum) 
                count++;
        }

        return count;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)
