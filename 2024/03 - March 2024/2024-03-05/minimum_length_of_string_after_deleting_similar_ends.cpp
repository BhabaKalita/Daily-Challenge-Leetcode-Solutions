int minimumLength(string s) {
    // Initialize two pointers i and j to the start and end of the string respectively
    int i = 0, j = s.size() - 1, ch = 0;

    // Loop until the pointers cross each other or until characters at i and j are not equal
    while (i < j && s[i] == s[j]) {
        // Store the character at index i (which is equal to the character at index j)
        ch = s[i];

        // Move i to the right until it points to a character different from ch
        while (i < j && s[i] == ch)
            ++i;

        // Move j to the left until it points to a character different from ch
        while (i < j && s[j] == ch)
            --j;
    }

    // If the character at index i is the same as ch, the string is already a palindrome
    // Hence, return 0. Otherwise, return the length of the remaining substring.
    return s[i] == ch ? 0 : j - i + 1;
}
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/