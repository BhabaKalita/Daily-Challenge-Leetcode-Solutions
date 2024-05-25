class Solution {
public:
    // Helper function to perform backtracking and find all valid word breaks
    void solve(string s, vector<string>& res, unordered_set<string>& st, vector<string>& temp) {
        // If the remaining string is empty, we have found a valid word break
        if (s.length() == 0) {
            string str = "";
            for (auto it : temp) {
                str += it + " ";
            }
            str.pop_back(); // Remove the trailing space
            res.push_back(str);
            return;
        }

        // Try every possible prefix of the current string
        for (int i = 0; i < s.length(); i++) {
            // If the prefix is in the dictionary, we continue the search with the remaining string
            if (st.count(s.substr(0, i + 1))) {
                temp.push_back(s.substr(0, i + 1)); // Add the prefix to the current path
                solve(s.substr(i + 1), res, st, temp); // Recur with the remaining string
                temp.pop_back(); // Backtrack to explore other possibilities
            }
        }
    }

    // Main function to return all valid word breaks
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res; // To store the final results
        vector<string> temp; // To store the current path of words
        unordered_set<string> st(wordDict.begin(), wordDict.end()); // Convert wordDict to a set for fast lookup

        solve(s, res, st, temp); // Start the backtracking process
        return res; // Return the result
    }
};
// Time Complexity: O(n^2) where n is the length of the input string.
// Space Complexity: O(n*k) where k is the number of words in the dictionary.)