#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int result = 0;
        dfs(arr, "", 0, result);
        return result;
    }

private:
    // Depth-first search function
    void dfs(const vector<string>& arr, const string& path, int idx, int& result) {
        // Check if the current path has unique characters
        if (isUniqueChars(path)) {
            result = max(result, static_cast<int>(path.length()));
        }

        // If we have reached the end of the array or the current path has duplicate characters,
        // stop the recursion for this branch
        if (idx == arr.size() || !isUniqueChars(path)) {
            return;
        }

        // Explore all possible combinations by adding each string from the array to the current path
        for (int i = idx; i < arr.size(); i++) {
            dfs(arr, path + arr[i], i + 1, result);
        }
    }

    // Helper function to check if a string has unique characters
    bool isUniqueChars(const string& s) {
        unordered_set<char> set;
        for (char c : s) {
            if (set.count(c)) {
                return false;
            }
            set.insert(c);
        }
        return true;
    }
};

/*
Time Complexity:O(2^n)
Space Complexity:O(n)
*/