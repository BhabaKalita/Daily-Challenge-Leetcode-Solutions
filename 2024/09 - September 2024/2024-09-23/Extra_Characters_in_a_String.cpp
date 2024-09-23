class Solution {
private:
    // Hash map to store the words from the dictionary for fast lookups.
    unordered_map<string, int> mp;
    
    // Memoization table to store the minimum extra characters for each index in the string.
    unordered_map<int, int> memo;

    // Recursive function to solve the problem starting from index 'ind'.
    int solve(string &s, int ind) {
        // Base case: if 'ind' is greater than or equal to the size of the string, no extra characters are needed.
        if (ind >= s.size())
            return 0;
        
        // If we have already computed the result for this index, return it from the memo table.
        if (memo.find(ind) != memo.end())
            return memo[ind];

        string temp = "";  // Temporary string to build substrings from the current index.
        int extra = INT_MAX;  // Variable to store the minimum extra characters.

        // Try building substrings starting from the current index 'ind'.
        for (int i = ind; i < s.size(); i++) {
            temp += s[i];  // Build the substring by adding the current character.

            // If the current substring exists in the dictionary, recursively solve for the remaining string.
            if (mp.find(temp) != mp.end()) {
                extra = min(extra, solve(s, i + 1));  // Recurse for the rest of the string after the matched substring.
            }
        }
        
        // Consider the case where no substring is matched, so count 1 extra character and move to the next index.
        extra = min(extra, 1 + solve(s, ind + 1));

        // Store the result in the memoization table and return it.
        memo[ind] = extra;

        return memo[ind];
    }

public:
    // Main function to calculate the minimum number of extra characters.
    int minExtraChar(string s, vector<string>& dictionary) {
        // Populate the hash map with all words from the dictionary for fast lookups.
        for (auto &val : dictionary) {
            mp[val]++;
        }

        // Start solving the problem from the 0th index of the string.
        return solve(s, 0);
    }
};
/*
  Time Complexity : O(n^2)
  Space Complexity : O(n + d * l)
*/
