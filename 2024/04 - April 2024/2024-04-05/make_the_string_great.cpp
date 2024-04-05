string makeGood(string s, int p = 0) {
    // Loop through each character in the string
    for (int i = 0; i < s.size(); ++i) {
        // Check if there are adjacent characters of different cases
        if (p > 0 && abs(s[i] - s[p - 1]) == 32)
            // If yes, remove the pair by moving the pointer p one position back
            --p;
        else
            // If no such adjacent characters, keep the character and move pointer p forward
            s[p++] = s[i];
    }
    // Return the substring of the processed string up to pointer p
    return s.substr(0, p);
}
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/