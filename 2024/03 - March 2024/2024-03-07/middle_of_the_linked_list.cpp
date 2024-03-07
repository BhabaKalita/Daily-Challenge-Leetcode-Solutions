class Solution {
public:
    // Function to find the middle node of a linked list
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers: fast and slow
        ListNode* fast = head;
        ListNode* slow = head;

        // Traverse the linked list with fast pointer moving twice as fast as slow pointer
        while (fast && fast->next) {
            fast = fast->next->next; // Move fast pointer two steps ahead
            slow = slow->next; // Move slow pointer one step ahead
        }

        // At this point, slow pointer is at the middle node
        return slow;
    }
};

/*
Time Complexity: O(n/2) ≈ O(n)
Sapce Complexity: O(1)
*/