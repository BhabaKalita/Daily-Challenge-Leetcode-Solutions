class Solution {
public:
    // Function to count how many words are consistent with the allowed characters
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[26] = {0}; // Array to track allowed characters, 0 means not allowed, 1 means allowed

        // Mark all characters that are in the 'allowed' string as allowed
        for(char c: allowed) {
            arr[c - 'a'] = 1; // Set the index corresponding to the character to 1
        }
        
        int count = 0; // Initialize counter for consistent strings

        // Iterate over each word in the words vector
        for(string word : words) {
            int flag = 1; // Flag to check if the word is consistent

            // Check each character in the word
            for(char c : word) {
                // If the character is not allowed, set flag to 0 and break the loop
                if(arr[c - 'a'] == 0) {
                    flag = 0;
                    break;
                }
            }

            // If the word was consistent (flag == 1), increment the count
            count += flag;
        }

        // Return the final count of consistent strings
        return count;
    }
};
/*
Time Complexity : O(n * m)
Space Complexity : O(n * m)
*/
