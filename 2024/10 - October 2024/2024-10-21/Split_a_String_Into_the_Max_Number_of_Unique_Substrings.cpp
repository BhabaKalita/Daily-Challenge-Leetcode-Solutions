class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen; // Set to store unique substrings
        return backtrack(0, s, seen);
    }

private:
    int backtrack(int start, const string& s, unordered_set<string>& seen) {
        // Base case: If we've reached the end of the string, return 0 splits
        if (start == s.size()) {
            return 0;
        }

        int maxSplits = 0; // Maximum number of unique splits found so far

        // Try all possible ending indices for the current substring
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start); // Extract the substring

            // Check if the substring is unique
            if (seen.find(substring) == seen.end()) {
                // If unique, add it to the seen set and recursively explore further splits
                seen.insert(substring);
                maxSplits = max(maxSplits, 1 + backtrack(end, s, seen));
                seen.erase(substring); // Remove the substring from the seen set to explore other possibilities
            }
        }

        return maxSplits; // Return the maximum number of unique splits found
    }
};

// Time Complexity: O(2^n)
// Reason:
// - The `backtrack` function explores all possible ways to split the string, which can lead to an exponential number of possibilities.
// - In the worst case, the recursion tree can have a depth of n (length of the string), and each node can have up to 2 branches (include or exclude the current substring).

// Space Complexity: O(n)
// Reason:
// - The `seen` set can store at most n unique substrings (in the worst case, where every substring is unique).
// - The recursion stack can also go up to n levels deep, storing the current index, substring, and the `seen` set.
