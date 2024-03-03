class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Check if head is NULL
        if (!head) return NULL;

        // Initialize fast and slow pointers to head
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++)  
            fast = fast->next;

        // If fast pointer becomes NULL, it means we need to remove the first node
        if (!fast) return head->next;

        // Move fast and slow pointers until fast reaches the end
        while (fast->next)
            fast = fast->next, slow = slow->next;

        // Remove the nth node from the end
        slow->next = slow->next->next;

        // Return the head of the modified linked list
        return head;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/