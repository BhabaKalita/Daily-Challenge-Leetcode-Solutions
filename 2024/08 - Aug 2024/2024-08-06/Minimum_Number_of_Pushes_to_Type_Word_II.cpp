class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0); // Initialize a vector of size 26 to count the frequency of each letter

        for(char &x : word) {
            mp[x - 'a']++; // Increment the frequency of the corresponding letter
        }

        // Sort the frequencies in descending order
        sort(mp.begin(), mp.end(), greater<int>());

        int res = 0; // Initialize the result to store the total number of presses

        // Calculate the minimum number of presses required
        for(int i = 0; i < 26; i++) {
            int freq = mp[i]; // Get the frequency of the i-th most frequent letter

            int press = i / 8 + 1; // Calculate the number of presses needed for this letter

            res += press * freq; // Add the presses needed for this letter to the result
        }

        return res; // Return the total number of presses
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)