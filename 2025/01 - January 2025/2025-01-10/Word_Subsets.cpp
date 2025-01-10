class Solution {
public:
    // Main function to find the words in A that are universal with respect to B
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> count(26), tmp(26); // Initialize two vectors of size 26 to count character frequencies
        int i;

        // Step 1: Process all words in B and find the required character frequencies
        // This loop processes all words in B and tracks the maximum frequency required for each character
        for (string b : B) {
            tmp = counter(b); // Get the character frequency count for the current word 'b'
            // Update the 'count' array to reflect the maximum frequency for each character
            for (i = 0; i < 26; ++i)
                count[i] = max(count[i], tmp[i]);
        }

        // Step 2: Check each word in A and see if it contains all required characters
        vector<string> res; // To store the result (words in A that are universal)
        for (string a : A) {
            tmp = counter(a); // Get the character frequency count for the current word 'a'
            // Check if this word contains all characters in the required count
            for (i = 0; i < 26; ++i)
                if (tmp[i] < count[i]) // If the current word 'a' does not satisfy the requirement for any character
                    break; // Exit the loop early
            // If all characters match the required count, add the word 'a' to the result
            if (i == 26) res.push_back(a);
        }

        return res; // Return the list of words in A that are universal
    }

    // Helper function to count the frequency of each character in a word
    vector<int> counter(string& word) {
        vector<int> count(26); // Initialize a count array to store frequencies for 26 characters
        for (char c : word) 
            count[c - 'a']++; // Increment the count for the corresponding character
        return count; // Return the frequency count
    }
};
// Time Complexity : O(n×m+p×k)
// Space Complexity : O(p)
