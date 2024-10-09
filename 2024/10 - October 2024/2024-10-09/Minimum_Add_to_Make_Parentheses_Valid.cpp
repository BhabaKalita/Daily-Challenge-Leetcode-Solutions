class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal = 0, ans = 0; // Initialize balance and answer

        for (auto x : s) {
            // Update balance based on the current character
            bal += (x == '(') ? 1 : -1;

            // If balance becomes negative, it means there's an unmatched ')'
            if (bal == -1) {
                ans += 1; // Increment answer to indicate a necessary ')'
                bal += 1; // Adjust balance to avoid unnecessary increments
            }
        }

        // Any remaining positive balance indicates unmatched '('
        return ans + bal;
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(1)
*/
