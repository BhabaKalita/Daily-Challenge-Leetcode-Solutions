class MyCircularDeque {
public:
    deque<int> dq;  // Deque to store elements.
    int size;       // Maximum capacity of the deque.
    
    // Constructor to initialize the deque with a fixed size.
    MyCircularDeque(int k) {
        dq = deque<int>();  // Create an empty deque.
        size = k;           // Set the maximum size.
    }
    
    // Insert an element at the front of the deque.
    bool insertFront(int value) {
        if (dq.size() < size) {  // Check if there's space in the deque.
            dq.push_front(value);  // Insert the element at the front.
            return true;  // Operation successful.
        }
        return false;  // Insertion failed because deque is full.
    }
    
    // Insert an element at the rear of the deque.
    bool insertLast(int value) {
        if (dq.size() < size) {  // Check if there's space in the deque.
            dq.push_back(value);  // Insert the element at the back.
            return true;  // Operation successful.
        }
        return false;  // Insertion failed because deque is full.
    }
    
    // Delete an element from the front of the deque.
    bool deleteFront() {
        if (!dq.empty()) {  // Check if the deque is not empty.
            dq.pop_front();  // Remove the element from the front.
            return true;  // Operation successful.
        }
        return false;  // Deletion failed because deque is empty.
    }
    
    // Delete an element from the rear of the deque.
    bool deleteLast() {
        if (!dq.empty()) {  // Check if the deque is not empty.
            dq.pop_back();  // Remove the element from the rear.
            return true;  // Operation successful.
        }
        return false;  // Deletion failed because deque is empty.
    }
    
    // Get the element at the front of the deque.
    int getFront() {
        if (dq.empty())  // If the deque is empty, return -1.
            return -1;
        return dq.front();  // Return the element at the front.
    }
    
    // Get the element at the rear of the deque.
    int getRear() {
        if (!dq.empty())  // If the deque is not empty, return the element at the rear.
            return dq.back();
        return -1;  // If the deque is empty, return -1.
    }
    
    // Check if the deque is empty.
    bool isEmpty() {
        return dq.empty();  // Return true if the deque is empty, otherwise false.
    }
    
    // Check if the deque is full.
    bool isFull() {
        return dq.size() == size;  // Return true if the deque is full.
    }
};
/*
  Time Complexity : O(1)
  Space Complexity : O(k)
*/
