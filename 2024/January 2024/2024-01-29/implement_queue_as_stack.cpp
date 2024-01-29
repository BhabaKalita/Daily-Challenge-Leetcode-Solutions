#include <stack>

class MyQueue {
private:
    std::stack<int> s1;  // Primary stack for enqueue operation
    std::stack<int> s2;  // Secondary stack for reversing elements during enqueue

public:
    MyQueue() {}

    // Enqueue operation
    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element onto s1
        s1.push(x);

        // Move all elements back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue operation
    int pop() {
        // Pop the front element from s1
        int temp = s1.top();
        s1.pop();
        return temp;
    }

    // Peek operation
    int peek() {
        // Return the front element of s1
        return s1.top();
    }

    // Check if the queue is empty
    bool empty() {
        return s1.empty();
    }
};

/*
Time Complexity: Enqueue (push): O(n), Peek: O(1)
Space Complexity: O(n)
*/