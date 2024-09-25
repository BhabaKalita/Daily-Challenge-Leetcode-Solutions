struct Trie {
    // Member variables:
    int score;  // Stores the total score of words that start with this prefix
    Trie *children[26];  // Array to store pointers to child nodes for each letter

    // Constructor:
    Trie() {
        score = 0;
        memset(children, 0, sizeof(children));
    }

    // Methods:
    void add(string &s, int i) {
        // Increment the score if the current prefix is a word.
        if (i) score++;

        // If the end of the word is reached, return.
        if (i == s.size()) return;

        // If the child node for the current letter doesn't exist, create it.
        if (!children[s[i] - 'a']) children[s[i] - 'a'] = new Trie();

        // Recursively add the remaining characters of the word to the child node.
        children[s[i] - 'a']->add(s, i + 1);
    }

    int dfs(string &s, int i) {
        // If the end of the word is reached, return the current score.
        if (i == s.size()) return score;

        // Return the current score plus the score of the child node for the next letter.
        return score + children[s[i] - 'a']->dfs(s, i + 1);
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        // Create a new Trie.
        Trie *trie = new Trie();

        // Add all words to the Trie.
        for (string &s : words) trie->add(s, 0);

        // Calculate the prefix scores for each word.
        vector<int> res;
        for (string &s : words) res.push_back(trie->dfs(s, 0));

        // Return the vector of prefix scores.
        return res;
    }
};
/*
  Time Complexity : O(N * k)
  Space Complexity : O(N * k)
  
*/
