class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // Use stringstream to split the sentence into individual words
        stringstream ss(sentence);

        // Initialize the word index (1-based, starting with the first word)
        int index = 1;
        string token = "";

        // Read each word from the sentence (words are separated by spaces)
        while (getline(ss, token, ' ')) { // Extract words into 'token' using space as a delimiter
            // Check if 'searchWord' is a prefix of the current word ('token')
            if (token.find(searchWord, 0) == 0) { 
                // If found, return the current index
                return index; 
            }

            // Increment the index to move to the next word
            index++;
        }

        // If no word starts with 'searchWord', return -1
        return -1; 
    }
};
// Time Complexity: O(m+n⋅k)
// Space Complexity: O(m+l)
