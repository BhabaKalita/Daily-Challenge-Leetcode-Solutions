#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        // Iterate through each word in the vector
        for(string &w : words) {
            // Check if the word is equal to its reverse
            if(w == string(rbegin(w), rend(w)))
                return w; // Return the word if it's a palindrome
        }
        return ""; // Return an empty string if no palindrome is found
    }
};
/*
Time Complexity: O(n * m)
Space Complexity: O(1)
*/