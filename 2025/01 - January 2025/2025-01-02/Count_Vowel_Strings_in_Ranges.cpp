class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // Initialize a prefix sum array to keep track of the cumulative count of vowel strings.
        vector<int> prefix(words.size());

        // Set of vowels for quick lookup.
        unordered_set<char> vowels = {'a','e','i','o','u'};

        int sum = 0; // To keep track of the number of valid vowel strings so far.
        for (int i = 0; i < words.size(); i++) {
            // Check if the first and last character of the word are vowels.
            if (vowels.find(words[i][0]) != vowels.end() && vowels.find(words[i][words[i].size()-1]) != vowels.end())
                sum++; // Increment the count if the current word satisfies the condition.
            
            prefix[i] = sum; // Update the prefix sum array with the current count.
        }

        // Initialize the answer array to store results for each query.
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            vector<int> curr = queries[i]; // Current query [left, right].

            // Calculate the count of vowel strings in the range [left, right].
            ans[i] = prefix[curr[1]] - (curr[0] == 0 ? 0 : prefix[curr[0]-1]);
        }

        return ans; // Return the results for all queries.
    }
};
// Time Complexity: O(n+m)
// Space Complexity: O(n+m)
