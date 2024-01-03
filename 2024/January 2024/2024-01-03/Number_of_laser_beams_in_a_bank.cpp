#include <vector>
#include <string>
#include <algorithm>  // Required for count function

class Solution {
public:
    // Function to calculate the number of laser beams in the bank
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();  // Number of rows in the bank
        int ans = 0, pre = 0;  // Initialize variables for total beams and previous row's '1' count

        // Iterate through each row in the bank
        for (int i = 0; i < n; i++) {
            // Count the number of '1's in the current row
            int onesCount = count(bank[i].begin(), bank[i].end(), '1');

            // If there are no '1's, skip to the next row
            if (onesCount == 0) {
                continue;
            }

            // Calculate the number of connections between the current row and the previous row
            ans += onesCount * pre;

            // Update 'pre' with the current row's '1' count for the next iteration
            pre = onesCount;
        }

        return ans;  // Return the total number of laser beams
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
