class Solution {
public:
    // Function to count how many strings in the list 'words' have 'pref' as a prefix
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;  // Initialize a counter variable to store the number of words with 'pref' as prefix
        
        // Iterate over each word in the 'words' vector
        for (string& word : words) {
            // Check if the current word starts with the given prefix 'pref'
            // The find() function returns 0 if the string 'pref' is found at the beginning of 'word'
            if (word.find(pref) == 0) {
                count++;  // If the word starts with 'pref', increment the count
            }
        }
        
        return count;  // Return the total count of words that start with 'pref'
    }
};
// Time complexity: O(n⋅m)
// Space complexity: O(1)
