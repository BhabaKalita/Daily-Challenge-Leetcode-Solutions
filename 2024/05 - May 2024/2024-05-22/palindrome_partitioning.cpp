class Solution {
public:
    // Main function to find all palindrome partitioning of a given string
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;  // To store the final list of palindrome partitions
        vector<string> temp;         // Temporary list to store current partition
        helper(s, 0, temp, res);     // Helper function to generate partitions
        return res;
    }

    // Helper function to recursively generate partitions
    void helper(string s, int idx, vector<string> &temp, vector<vector<string>> &res) {
        // If the end of the string is reached, add the current partition to the result
        if (idx == s.size()) {
            res.push_back(temp);
            return;
        }

        // Iterate through the string to create possible partitions
        for (int i = idx; i < s.size(); i++) {
            // Check if the current substring is a palindrome
            if (isPalindrome(s, idx, i)) {
                // Add the current palindrome substring to the temporary list
                temp.push_back(s.substr(idx, i - idx + 1));
                // Recur to generate partitions for the remaining substring
                helper(s, i + 1, temp, res);
                // Backtrack by removing the last added substring
                temp.pop_back();    
            }
        }
    }

    // Function to check if a substring is a palindrome
    bool isPalindrome(string s, int x, int y) {
        while (x < y) {
            if (s[x++] != s[y--])
                return false;
        }
        return true;
    }
};
/*
Time Complexity: O(n^2 * 2^n)
Space Complexity: O(n * 2^n)
*/