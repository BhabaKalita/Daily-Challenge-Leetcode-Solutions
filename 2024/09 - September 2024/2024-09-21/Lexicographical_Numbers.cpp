class Solution {
public:
    // Function to return numbers from 1 to n in lexicographical order
    vector<int> lexicalOrder(int n) {
        // 'cur' is the current number we're building in lexicographical order, starting at 1
        int cur = 1;
        // 'ans' stores the result, i.e., numbers in lexicographical order
        vector<int> ans;

        // We need to insert 'n' numbers into 'ans', so loop 'n' times
        for (int i = 0; i < n; i++) {
            // Add the current number to the result list
            ans.push_back(cur);

            // Try to move to the next number by multiplying by 10 (go deeper in lexicographical tree)
            if (cur * 10 <= n) {
                cur *= 10;  // For example, from 1 -> 10, or 2 -> 20, etc.

            } else {
                // If multiplying by 10 exceeds 'n', increment the current number
                // Example: if cur = 19, then next should be 2, not 190 (since 190 > n)
                if (cur >= n) {
                    cur /= 10;  // If the current number is >= n, divide by 10 to move up a level
                }

                // Increment the current number
                cur++;

                // Handle trailing zeroes, ensuring we skip invalid numbers like 100, 200, etc.
                // Example: if cur = 10, then divide it by 10 to get 1, and increment to 2
                while (cur % 10 == 0) {
                    cur /= 10;
                }
            }
        }
        // Return the result containing all numbers from 1 to 'n' in lexicographical order
        return ans;
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(1)
*/
