class CustomStack {
public:
    int n;  // Maximum size of the stack
    stack<int> stack;  // Stack to store the elements
    vector<int> inc;   // Vector to store the pending increment values

    // Constructor to initialize the stack with a maximum size 'n'
    CustomStack(int n) {
        this->n = n;  // Store the max size in the object
    }

    // Pushes the element 'x' onto the stack if it has not reached its maximum size
    void push(int x) {
        if (stack.size() < n) {  // Check if the current stack size is less than the max size
            stack.push(x);  // Push the element onto the stack
            inc.push_back(0);  // Add a 0 to the 'inc' array as no increment applies to this new element yet
        }
    }

    // Pops the top element from the stack and returns it, applying any pending increments
    int pop() {
        if (stack.empty()) return -1;  // If the stack is empty, return -1

        // Before popping, apply the increment to the element below the top, if applicable
        if (inc.size() > 1) 
            inc[inc.size() - 2] += inc.back();  // Add the top element's increment to the next-to-top element
        
        int res = stack.top() + inc.back();  // Get the top element and apply its increment
        stack.pop();  // Remove the top element from the stack
        inc.pop_back();  // Remove the increment associated with the top element
        return res;  // Return the incremented value of the top element
    }

    // Increments the bottom 'k' elements of the stack by 'val'
    void increment(int k, int val) {
        if (!stack.empty()) {  // Check if the stack is not empty
            // Calculate the index for the bottom 'k' elements or all elements if there are fewer than 'k'
            int idx = min(k, (int)inc.size()) - 1;
            inc[idx] += val;  // Add the increment value to the bottom k-th element (or the top if less than k elements)
        }
    }
};
/*
  Time Complexity : O(1)
  Space Complexity : O(n)
*/
