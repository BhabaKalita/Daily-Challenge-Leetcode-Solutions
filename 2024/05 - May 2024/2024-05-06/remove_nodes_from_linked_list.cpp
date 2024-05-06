class Solution {
public:
    // Function to remove nodes with values smaller than their successors
    ListNode* removeNodes(ListNode* head) {
        // If head is NULL, return NULL
        if (!head) return NULL;

        // Recursively call removeNodes for the next node
        head->next = removeNodes(head->next);

        // If head's next node exists and its value is smaller than head's value,
        // return head's next node, otherwise, return head
        return head->next && head->val < head->next->val ? head->next : head; 
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/