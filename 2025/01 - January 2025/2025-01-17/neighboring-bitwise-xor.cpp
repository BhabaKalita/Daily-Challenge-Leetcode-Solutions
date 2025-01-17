class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = accumulate(derived.begin(), derived.end(), 0);
        return sum % 2 == 0;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
