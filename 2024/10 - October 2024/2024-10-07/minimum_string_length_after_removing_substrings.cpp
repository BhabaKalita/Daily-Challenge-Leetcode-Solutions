class Solution {
public:
    int minLength(string s) {
        // Create an empty stack to store characters
        stack<char> st;

        // Iterate over each character in the string
        for (char c : s) {
            // Check if the current character forms a valid pair with the top element on the stack
            if (c == 'B' && !st.empty() && st.top() == 'A') {
                // If a valid pair is found, remove them from the stack
                st.pop();
            } else if (c == 'D' && !st.empty() && st.top() == 'C') {
                // Same logic for another valid pair
                st.pop();
            } else {
                // If the character doesn't form a valid pair, push it onto the stack
                st.push(c);
            }
        }

        // The number of elements remaining in the stack represents the minimum length
        return st.size();
    }
};

// Time Complexity: O(n)
// Reason: The loop iterates over each character in the string (n times). Inside the loop, constant time operations like comparisons and stack operations occur.

// Space Complexity: O(n)
// Reason: In the worst case, the stack might hold all characters from the string (n elements) if none form valid pairs.
