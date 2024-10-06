class Solution {
public:
    // Function to split the input string `s` into a vector of words
    inline static vector<string> getVec(string& s) {
        stringstream ss(s);  // Create a stringstream object to split the string
        vector<string> ans;  // Vector to store the words
        string w;  // Temporary string to hold each word
        
        // Extract words from the stringstream and push them into the vector
        while(ss >> w)
            ans.push_back(w);
        
        // Clear the stringstream (though it's not really needed here)
        ss.clear();
        return ans;  // Return the vector of words
    }

    // Function to check if two sentences are similar
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Convert both sentences into vectors of words
        auto s1 = getVec(sentence1), s2 = getVec(sentence2);
        int n1 = s1.size(), n2 = s2.size();  // n1 is the number of words in sentence1, n2 in sentence2

        // If sentence1 is longer, swap the variables to make sure n1 <= n2
        if(n1 > n2) swap(n1, n2), swap(s1, s2);

        int l = 0;          // Pointer to track from the left side
        int r2 = n2 - 1;    // Pointer to track from the right side in the larger sentence
        int r1 = n1 - 1;    // Pointer to track from the right side in the smaller sentence

        // Compare words from the start (left side)
        for(; l < n1 && s1[l] == s2[l]; l++);  // Move `l` until words differ or we exhaust s1

        // Compare words from the end (right side)
        for(; r1 >= 0 && s1[r1] == s2[r2]; r2--, r1--);  // Move `r1` and `r2` until words differ

        // If the left pointer `l` has surpassed the right pointer `r1`, sentences are similar
        return r1 < l;
    }
};
/*
  Time Complexity : O(m1+m2+n1)
  Space Complexity : O(n1+n2)
*/
