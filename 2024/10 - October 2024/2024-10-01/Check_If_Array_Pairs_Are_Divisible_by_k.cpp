class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);  // Frequency array to store the count of each remainder when divided by k

        // Step 1: Calculate frequency of remainders
        for (int num : arr) {
            int rem = num % k;  // Calculate the remainder of num when divided by k

            if (rem < 0)  // Adjust negative remainders to be positive
                rem += k;

            freq[rem]++;  // Increment the frequency count for this remainder
        }

        // Step 2: Check if the frequency of remainder 0 is even (pairs can only be formed in even numbers)
        if (freq[0] % 2 != 0)  // If there is an odd number of elements with remainder 0, they cannot form pairs
            return false;

        // Step 3: Check if for each remainder 'i', the count of 'i' is equal to the count of 'k - i'
        for (int i = 1; i <= k / 2; i++) {
            // For each remainder i, check if its complementary remainder (k - i) has the same frequency
            if (freq[i] != freq[k - i])  // If frequencies don't match, it's impossible to form valid pairs
                return false;
        }

        return true;  // If all checks pass, return true (pairs can be formed)
    }
};

/*
  Time Complexity : O(n+k)
  Space Complexity : O(n)
*/
