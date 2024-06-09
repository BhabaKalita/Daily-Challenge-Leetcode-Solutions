class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // A map to keep track of the frequency of each remainder
        unordered_map<int, int> remainderFrequency;
        remainderFrequency[0] = 1;  // There's always one way to have a sum divisible by k with zero elements.

        int sum = 0;  // To store the cumulative sum of the elements
        int res = 0;  // To store the result, i.e., the count of subarrays divisible by k

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];  // Update the cumulative sum

            // Calculate remainder of the current sum with respect to k
            int remainder = sum % k;

            // Adjust remainder to be in the range [0, k-1] (normalize negative remainders)
            if(remainder < 0) {
                remainder += k;
            }

            // If this remainder has been seen before, it means there are subarrays ending at the current index that sum to a multiple of k
            if(remainderFrequency.find(remainder) != remainderFrequency.end()) {
                res += remainderFrequency[remainder];  // Add the count of such subarrays to the result
            }

            // Increment the count of this remainder in the map
            remainderFrequency[remainder]++;
        }

        return res;  // Return the total count of subarrays whose sum is divisible by k
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(min(n, k)), where nn is the number of elements in nums and kk is the divisor.
*/