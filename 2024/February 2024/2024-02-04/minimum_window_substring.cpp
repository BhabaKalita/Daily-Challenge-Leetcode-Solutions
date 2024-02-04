#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Initialize an array to store the count of characters in string t
        vector<int> countC(128, 0);

        // Populate the count array for characters in string t
        for (auto ch : t)
            countC[ch]++;

        // Variables to track the window and result
        int n = s.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        int counter = t.size();

        // Sliding window algorithm
        while (end < n) {
            // If the character at end is in string t, decrement its count
            if (countC[s[end++]]-- > 0)
                counter--;

            // Check if all characters from t are in the current window
            while (counter == 0) {
                // If the current window is smaller than the minimum window length
                if (end - begin < d) {
                    head = begin;
                    d = end - head;
                }

                // If the character at begin is in string t, increment its count
                if (countC[s[begin++]]++ == 0)
                    counter++;
            }
        }

        // Return the minimum window substring
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
/*
- Time Complexity: O(N)
- Space Complexity: O(1)
  */