class Solution {
public:
    int minSteps(string s, string t) {
        // Create vectors to store the count of each character in the alphabet for both strings
        vector<int> count_s(26, 0), count_t(26, 0);

        // Count occurrences of each character in string s
        for (char c : s) {
            count_s[c - 'a']++;
        }

        // Count occurrences of each character in string t
        for (char ch : t) {
            count_t[ch - 'a']++;
        }

        // Calculate the steps needed to make the two strings anagrams
        int steps = 0;
        for (int i = 0; i < 26; i++) {
            if (count_s[i] > count_t[i]) {
                // If count in string s is greater than count in string t, add the difference to steps
                steps += count_s[i] - count_t[i];
            }
        }

        // Return the total steps needed
        return steps;
    }
};

/*
Time Complexity: O(max(N, M))
Space Complexity: O(1)
*/