class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize two pointers: nextNode to store the next node of current head
        // and prevNode to store the previous node (initially NULL)
        ListNode *nextNode, *prevNode = NULL;

        // Iterate through the linked list until head becomes NULL
        while (head) {
            // Store the next node of the current head
            nextNode = head->next;
            // Reverse the link, pointing current head's next to the previous node
            head->next = prevNode;
            // Move prevNode to the current head
            prevNode = head;
            // Move head to the next node in the original order
            head = nextNode;
        }
        // Return the new head of the reversed list
        return prevNode;   
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/  