string minRemoveToMakeValid(string s) {
  stack<int> st; // Create a stack to keep track of the indices of opening parentheses
  for (auto i = 0; i < s.size(); ++i) { // Iterate through each character in the string
    if (s[i] == '(') st.push(i); // If the current character is an opening parenthesis, push its index onto the stack
    if (s[i] == ')') { // If the current character is a closing parenthesis
      if (!st.empty()) st.pop(); // If there is a corresponding opening parenthesis in the stack, pop it
      else s[i] = '*'; // Otherwise, mark this closing parenthesis for removal by replacing it with '*'
    }
  }
  while (!st.empty()) { // After iterating through the string, there might be unmatched opening parentheses left in the stack
    s[st.top()] = '*'; // Mark those unmatched opening parentheses for removal by replacing them with '*'
    st.pop();
  }
  s.erase(remove(s.begin(), s.end(), '*'), s.end()); // Remove all '*' characters from the string, effectively removing unmatched parentheses
  return s; // Return the modified string with minimum removals to make it a valid parentheses sequence
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/