class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    
    // Check if str1 is a prefix and suffix of str2
    return (len1 <= len2) && (str2.substr(0, len1) == str1) && (str2.substr(len2 - len1, len1) == str1);
}

int countPrefixSuffixPairs(const vector<string>& words) {
    int n = words.size();
    int count = 0;
    
    // Iterate over all pairs (i, j) where i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isPrefixAndSuffix(words[i], words[j])) {
                ++count;
            }
        }
    }
    
    return count;
}
};
// T.C - O(n2⋅m)
// S.C - O(1)
