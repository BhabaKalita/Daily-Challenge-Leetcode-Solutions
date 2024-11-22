class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        // Create an unordered_map to store the frequency of patterns (key: pattern, value: frequency)
        unordered_map<string, int> patFreq;
        
        // Iterate through each row in the matrix
        for (const auto& row : mat) {
            string pattern; // String to represent the pattern of the current row

            // Check the first bit of the row to determine the pattern to normalize
            if (row[0] == 0) {
                // If the first bit is 0, keep the pattern as is
                for (int bit : row) 
                    pattern += to_string(bit); // Append each bit to the pattern string
            } else {
                // If the first bit is 1, flip all the bits (using XOR with 1)
                for (int bit : row) 
                    pattern += to_string(bit ^ 1); // Append the flipped bit to the pattern string
            }
            
            // Increment the frequency of the pattern in the map
            patFreq[pattern]++;
        }
        
        int maxFreq = 0; // Variable to store the maximum frequency of any pattern

        // Iterate through the frequency map to find the maximum frequency
        for (const auto& pair : patFreq) {
            maxFreq = max(maxFreq, pair.second); // Update maxFreq with the highest frequency
        }

        return maxFreq; // Return the maximum frequency, which is the result
    }
};
// Time Complexity: O(m⋅n)
// Space Complexity: O(m⋅n)
