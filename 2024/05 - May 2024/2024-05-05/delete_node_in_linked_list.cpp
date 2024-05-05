class Solution {
public:
    // Method to delete a node from a singly linked list
    void deleteNode(ListNode* node) {
        // Copy the next node's data to the current node
        auto next = node->next;
        *node = *next;
        // Delete the next node
        delete next;
    }
};
/*
Time Complexity: O(1)
Space Complexity: O(1)
*/