class Solution {
public:
    // Function to merge nodes between zeros and return the modified list
    ListNode* mergeNodes(ListNode* head) {
        // Move to the next node as the head is a dummy node with value 0
        head = head->next;

        // Base case: if head is NULL, return NULL
        if(head == NULL)
            return head;

        ListNode* temp = head; // Temporary pointer to traverse the list
        int sum = 0;           // Variable to accumulate the sum of node values

        // Traverse the list until a node with value 0 is found
        while(temp != NULL && temp->val != 0) {
            sum += temp->val; // Add the current node's value to sum
            temp = temp->next; // Move to the next node
        }

        head->val = sum; // Update the current node's value with the accumulated sum
        head->next = mergeNodes(temp); // Recursively process the remaining list

        return head; // Return the modified list's head
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)