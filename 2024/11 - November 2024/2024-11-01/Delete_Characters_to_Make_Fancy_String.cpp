class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";          // Initialize an empty string to store the resulting "fancy" string
        ans.push_back(s[0]);      // Add the first character of the input string 's' to 'ans'
        int n = s.size(), cnt = 1; // Get the size of the input string and initialize a counter to track consecutive characters

        // Loop through the string starting from the second character
        for(int i = 1; i < n; i++) {
            if(s[i] == ans.back()) {   // Check if the current character is the same as the last character in 'ans'
                cnt++;                 // Increment the counter if characters are consecutive and identical
                if(cnt < 3)            // Only add the character to 'ans' if there are fewer than 3 consecutive duplicates
                    ans.push_back(s[i]);
            } else {                   // If the current character is different from the last character in 'ans'
                cnt = 1;               // Reset the counter since we have a new character
                ans.push_back(s[i]);   // Add the new character to 'ans'
            }
        }
        return ans;                    // Return the modified "fancy" string
    }
};
/*
Time Complexity : O(n)
Space Complexity : O(n)
*/
