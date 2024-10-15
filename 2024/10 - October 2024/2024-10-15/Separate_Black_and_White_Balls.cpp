class Solution {
public:
    // Function to calculate the minimum steps required
    long long minimumSteps(string s) {
        // Variables to keep track of '1's (white) and the result (res)
        long long white = 0;  // Counts the number of '1's encountered so far
        long long res = 0;    // Stores the final result (minimum steps)

        // Iterate through each character of the string
        for(int i = 0; i < s.size(); i++) {
            // If the current character is '0', add the number of '1's seen so far to the result
            if(s[i] == '0')
                res += white;
            // If the current character is '1', increment the count of '1's (white)
            else if(s[i] == '1')
                white++;
        }

        // Return the final result (total minimum steps)
        return res;
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(1)
*/
