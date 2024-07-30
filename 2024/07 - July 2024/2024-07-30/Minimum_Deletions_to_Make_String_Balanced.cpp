class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();  // Get the size of the string

        int count_a = 0;   // Initialize the count of 'a's to 0
        int tot = INT_MAX; // Initialize the minimum deletions to a large value

        // Count the number of 'a's in the string
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == 'a')
                count_a++;
        }

        int count_b = 0;   // Initialize the count of 'b's to 0

        // Traverse the string and compute the minimum deletions
        for(int j = 0; j < n; j++) {
            if(s[j] == 'a')
                count_a--; // Decrement count_a when 'a' is encountered

            // Calculate the minimum deletions by comparing the current state
            tot = min(tot, count_a + count_b);

            if(s[j] == 'b')
                count_b++; // Increment count_b when 'b' is encountered
        }

        return tot; // Return the minimum deletions needed
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)