long long wonderfulSubstrings(string word) {
    // Initialize an array to store counts of masks.
    long cnt[1024] = { 1 }; // 1024 is 2^10, representing all possible bit masks for lowercase letters.
    long mask = 0; // Initialize the mask to 0.
    long long res = 0; // Initialize the result.

    // Iterate through each character in the word.
    for (auto ch : word) {
        // Update the mask by toggling the corresponding bit for the current character.
        mask ^= 1 << (ch - 'a');

        // Increment the result by the count of the current mask.
        res += cnt[mask];

        // For each possible toggled bit (0 to 9), increment the result by the count of the corresponding toggled mask.
        for (auto n = 0; n < 10; ++n)
            res += cnt[mask ^ (1 << n)];

        // Increment the count of the current mask.
        ++cnt[mask];
    }

    return res; // Return the final result.
}
// Time Complexity: O(N) where N is the length of the input string.
// Space Complexity: O(1) as no extra space is used.