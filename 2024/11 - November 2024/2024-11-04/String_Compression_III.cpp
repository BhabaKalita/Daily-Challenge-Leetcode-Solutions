class Solution {
public:
    string compressedString(string word) {
        int cnt = 1; // Initialize a counter to track consecutive identical characters
        int n = word.size();

        string res = ""; // Initialize an empty string to store the compressed result

        // Initialize the current character and its count
        char ch = word[0];

        for (int i = 1; i < n; i++) {
            // If the current character is the same as the previous one and the count is less than 9, increment the count
            if (word[i] == ch && cnt < 9) {
                cnt++;
            } else {
                // Otherwise, append the current character and its count to the result
                res.push_back(cnt + '0'); // Convert count to a character and append
                res.push_back(ch);
                // Update the current character and reset the count
                ch = word[i];
                cnt = 1;
            }
        }

        // Append the last character and its count to the result
        res.push_back(cnt + '0');
        res.push_back(ch);

        return res;
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(n)
*/
