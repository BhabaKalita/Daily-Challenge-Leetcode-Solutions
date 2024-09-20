class Solution {
public:
    // Function to find the shortest palindrome by adding characters in front of string 's'
    string shortestPalindrome(string s) {
        // Find the length of the longest palindromic prefix using the KMP algorithm
        int count = kmp(string(s.rbegin(), s.rend()), s);
        
        // Form the palindrome by adding the necessary characters in front of 's'
        // Add the non-palindromic part of the reversed string to the front of 's'
        return string(s.rbegin(), s.rend()).substr(0, s.size() - count) + s;
    }

    // Helper function that uses the KMP algorithm to calculate the length of the
    // longest prefix of 'p' that matches a suffix of 'txt'
    int kmp(const string &txt, const string &p) {
        // Concatenate 'p' (pattern) and 'txt' (text) with a '#' separator
        // 'nwStr' = pattern + '#' + reversed text (no matching across '#')
        string nwStr = p + '#' + txt;

        // Create the prefix function (pi array) for the KMP algorithm
        vector<int> pi(nwStr.size(), 0);

        // 'i' is the current index we're evaluating, 'k' is the length of the
        // current matching prefix that is also a suffix
        int i = 1, k = 0;

        // Loop through the string 'nwStr' to compute the pi array
        while (i < nwStr.size()) {
            // If the characters at positions 'i' and 'k' match, extend the current match
            if (nwStr[i] == nwStr[k]) {
                k++;            // Increment the length of the matching prefix
                pi[i] = k;      // Store the length of the matching prefix in the pi array
                i++;            // Move to the next character
            } else {
                // If the characters don't match, we check for the last matching prefix
                if (k > 0) {
                    // If there's a previous match, jump back to the last longest prefix
                    k = pi[k - 1];
                } else {
                    // If no match exists, simply move to the next character
                    pi[i] = 0;
                    i++;
                }
            }
        }
        // Return the length of the longest matching prefix which is stored in the last value of the pi array
        return pi.back();
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(n)
*/
