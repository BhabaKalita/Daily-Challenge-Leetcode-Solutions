class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = target.length(), mod = 1e9 + 7;  // n is the length of target string, mod is used for large number handling
        vector<long> res(n + 1);  // This will store the number of ways to form the target up to each length.
        res[0] = 1;  // Base case: There is one way to form an empty target (by choosing nothing).
        
        // Iterate through each column of the words list
        for (int i = 0; i < words[0].length(); ++i) {  
            vector<int> count(26);  // This will store the frequency of each character ('a' to 'z') in the i-th column of all words.
            
            // Count occurrences of each character in the i-th position of all words
            for (auto& w : words)
                count[w[i] - 'a']++;  // w[i] is the character in the i-th column, 'a' is subtracted to map it to 0-based index
            
            // Update the number of ways to form the target using the current column's character frequencies
            for (int j = n - 1; j >= 0; --j) {  // Traverse from the end of the target (right to left)
                res[j + 1] += res[j] * count[target[j] - 'a'] % mod;  // Multiply previous result by the count of the target[j] character
            }
        }
        
        return res[n] % mod;  // Return the result for the full target length, modded to handle large numbers
    }
};
// Time Complexity: O(k * m * n)
// Space Complexity: O(n) 
