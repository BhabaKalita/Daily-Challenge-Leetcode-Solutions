vector<string> commonChars(vector<string>& A) {
    // Initialize a vector to store the minimum frequency of each character across all strings
    vector<int> cnt(26, INT_MAX);
    vector<string> res;  // Result vector to store the common characters

    // Iterate through each string in the input vector A
    for (auto s : A) {
        // Initialize a vector to count the frequency of each character in the current string
        vector<int> cnt1(26, 0);

        // Count the frequency of each character in the current string
        for (auto c : s) ++cnt1[c - 'a'];

        // Update the minimum frequency of each character
        for (auto i = 0; i < 26; ++i) cnt[i] = min(cnt[i], cnt1[i]);
    }

    // Collect the common characters based on their minimum frequency
    for (auto i = 0; i < 26; ++i) {
        // Add the character 'i' as many times as its minimum frequency to the result vector
        for (auto j = 0; j < cnt[i]; ++j) res.push_back(string(1, i + 'a'));
    }

    return res;  // Return the result vector
}
/*
Time Complexity: O(n * m) where n is the number of strings in A and n is the average length of the strings.
Space Complexity: O(1)
*/