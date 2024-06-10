class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // Initialize a count array for heights (0-100), set all counts to 0.
        vector<int> counts(101, 0);

        int mismatch = 0; // Variable to count mismatches

        // Count the occurrence of each height in the input array
        for(int i = 0; i < heights.size(); i++) {
            counts[heights[i]]++;
        }

        int x = 1; // Start comparing from height 1
        int y = 0; // Index to traverse the original heights array

        // Traverse through all possible heights (from 1 to 100)
        while(x < 101) {
            if(counts[x] == 0) {
                // If there are no students of height x, move to the next height
                x++;
            } else {
                // Check if the current height (x) matches the height at position y in the original array
                if(x != heights[y]) {
                    mismatch++; // Increment mismatch if heights do not match
                }

                // Move to the next student in the original array
                y++;

                // Decrease the count for the current height, as one student of height x is considered
                counts[x]--;
            }
        }

        return mismatch; // Return the total number of mismatches
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/