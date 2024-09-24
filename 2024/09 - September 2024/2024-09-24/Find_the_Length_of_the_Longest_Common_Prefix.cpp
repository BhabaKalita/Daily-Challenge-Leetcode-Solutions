class Solution {
public:
    // Function to find the length of the longest common prefix between the numbers in two arrays.
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Unordered map to store all possible prefixes from arr1 and their counts.
        unordered_map<string, int> prefixMap;

        // Iterate over all the numbers in arr1.
        for (int num : arr1) {
            string prefix = "";  // Initialize an empty prefix string.
            string str = to_string(num);  // Convert the integer to a string.

            // For each character in the number's string representation, build the prefix.
            for (auto ch : str) {
                prefix += ch;  // Add the current character to the prefix.
                prefixMap[prefix]++;  // Store the prefix in the map (or increment its count).
            }
        }

        int mxLen = 0;  // Variable to store the maximum length of a common prefix.

        // Iterate over all the numbers in arr2.
        for (int num : arr2) {
            string prefix = "";  // Initialize an empty prefix string.
            string str = to_string(num);  // Convert the integer to a string.

            // For each character in the number's string representation, build the prefix.
            for (auto ch : str) {
                prefix += ch;  // Add the current character to the prefix.
                
                // If the prefix exists in the map (i.e., it's a common prefix), check its length.
                if (prefixMap.find(prefix) != prefixMap.end()) {
                    // Update the maximum length if this prefix is longer than the previous one.
                    mxLen = max(mxLen, static_cast<int>(prefix.size()));
                }
            }
        }

        // Return the length of the longest common prefix found.
        return mxLen;
    }
};
/*
  Time Complexity: O(n⋅k+m⋅k) where (n) is the length of arr1, (m) is the length of arr2, and (k) is the average number of digits in the integers.
  Space Complexity: O(n⋅k)
*/
