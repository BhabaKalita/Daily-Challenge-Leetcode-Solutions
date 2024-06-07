class Solution {
public:
    // Function to get the root word from the dictionary if it exists.
    string getRoot(string &word, unordered_set<string> &st) {
        string root;
        // Iterate through the word, checking prefixes starting from length 1 up to the full word length.
        for(int i = 1; i < word.length(); i++) {
            root = word.substr(0, i); // Get the prefix of length i.
            if(st.count(root)) // Check if this prefix is in the dictionary set.
                return root; // Return the prefix if it is found in the set.
        }
        return word; // If no prefix is found in the set, return the original word.
    }

    // Function to replace words in a sentence with their root forms from the dictionary.
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Convert the dictionary to an unordered set for O(1) average time complexity lookups.
        unordered_set<string> st(begin(dictionary), end(dictionary));
        string res; // This will store the resulting sentence after replacements.
        stringstream ss(sentence); // String stream for parsing the sentence.
        string word; // Temporary variable to hold each word.

        // Process each word in the sentence.
        while(getline(ss, word, ' ')) {
            // Append the root or the original word (if no root is found) followed by a space.
            res += getRoot(word, st) + " ";
        }

        // Remove the trailing space from the result string.
        res.pop_back();

        return res; // Return the modified sentence.
    }
};

/*
Time Complexity: O(N+M×L)
Space Complexity: O(N×average word length)+O(total number of characters in the sentence)
*/