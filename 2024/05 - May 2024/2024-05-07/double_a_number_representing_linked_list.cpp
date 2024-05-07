ListNode* doubleIt(ListNode* head) {
    // Check if the value of the head node is greater than 4
    if (head->val > 4)
        // If yes, insert a new node with value 0 before the head
        head = new ListNode(0, head);

    // Traverse the linked list
    for(ListNode* node = head; node; node = node->next) {
        // Double the value of the current node and take modulo 10
        node->val = (node->val * 2) % 10;
        // If the next node exists and its value is greater than 4
        if (node->next && node->next->val > 4)
            // Increment the value of the current node
            node->val++;
    }

    // Return the modified head of the linked list
    return head;
}
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/