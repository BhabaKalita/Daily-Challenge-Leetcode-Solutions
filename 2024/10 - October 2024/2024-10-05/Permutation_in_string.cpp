class Solution {
public:
    // Function to count the frequency of each character in a given substring [l, r]
    array<int, 26> count(string& s, int l, int r) {
        // Initialize an array of size 26 (for each letter in the alphabet) to 0
        array<int, 26> freq = {0};
        
        // Iterate over the substring and update the frequency count
        for(int i = l; i <= r; i++)
            freq[s[i] - 'a']++;  // Increment the frequency of the corresponding character
        return freq;  // Return the frequency array
    }

    // Function to check if a permutation of s1 is a substring of s2
    bool checkInclusion(string& s1, string& s2) {
        const int n1 = s1.size(), n2 = s2.size();  // n1 is the length of s1, n2 is the length of s2
        
        // If s2 is shorter than s1, a permutation of s1 cannot exist in s2
        if(n2 < n1) return 0;

        // Get the frequency counts for the entire s1 and the first substring of s2 of length n1
        auto freq1 = count(s1, 0, n1 - 1);  // Frequency array of s1
        auto freq2 = count(s2, 0, n1 - 1);  // Frequency array of the first n1 characters of s2

        // If the frequency arrays are the same, return true (s1's permutation is a substring of s2)
        if(freq1 == freq2) return 1;

        // Sliding window technique: move the window of size n1 across s2
        for(int l = 1, r = n1; r < n2; l++, r++) {
            // Update the frequency array by removing the leftmost character and adding the rightmost character
            freq2[s2[l - 1] - 'a']--;  // Remove the character going out of the window
            freq2[s2[r] - 'a']++;      // Add the new character coming into the window

            // If the frequency arrays match, return true (a permutation of s1 is found)
            if(freq2 == freq1) return 1;
        }

        // If no permutation is found, return false
        return 0;
    }
};
/*
  Time complexity: O(n1+n2)
  Space complexity: O(1)
*/
