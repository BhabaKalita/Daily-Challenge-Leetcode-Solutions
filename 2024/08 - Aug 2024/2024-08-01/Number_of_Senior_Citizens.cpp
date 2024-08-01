class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0; // Initialize the counter for seniors

        // Iterate through each detail string in the input vector
        for(auto &x : details) {
            // Extract the substring representing the age (characters 11 and 12) and convert it to an integer
            int y = stoi(x.substr(11, 2));

            // Increment the counter if the age is greater than 60
            ans += (y > 60);

        }

        // Return the total count of seniors
        return ans;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)