class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size(); 
        vector<string> ans; // Vector to store the result (substrings)

        // Iterate through each word in the input vector
        for (int i = 0; i < n; ++i) { 
            // Iterate through all other words in the vector
            for (int j = 0; j < n; ++j) { 
                // Check if the current word (words[i]) is a substring of another word (words[j])
                // and they are not the same word (i != j)
                if (i != j && words[j].find(words[i]) != string::npos) { 
                    // If the current word is a substring, add it to the result vector
                    ans.push_back(words[i]); 
                    // Break the inner loop since we've found at least one match
                    break; 
                }
            }
        }

        return ans;
    }
};
// Time Complexity : O(n^2 * max(m))
// Space Complexity : O(n)
