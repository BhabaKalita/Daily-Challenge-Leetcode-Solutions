class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // Combine the two sentences into a single string with a space separator.
        string s = s1 + " " + s2;

        // Create a string stream to parse the combined string.
        stringstream ss(s);

        // Use an unordered map to store word counts.
        unordered_map<string, int> mp;

        // Iterate over each word in the combined string.
        string tmp;
        while (ss >> tmp) {
            // Increment the count of the current word in the map.
            mp[tmp]++;
        }

        // Create a vector to store uncommon words.
        vector<string> res;

        // Iterate over the word counts in the map.
        for (auto& str : mp) {
            // If a word appears only once (count is 1), it's uncommon.
            if (str.second == 1) {
                // Add the uncommon word to the result vector.
                res.emplace_back(str.first);
            }
        }

        // Return the vector of uncommon words.
        return res;
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(n)
*/
