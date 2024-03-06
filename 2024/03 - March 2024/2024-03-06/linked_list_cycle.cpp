class Solution {
public:
    // Function to detect cycle in a linked list
    bool hasCycle(ListNode *head) {
        // Initialize two pointers: slow and fast
        ListNode *slow = head;
        ListNode *fast = head;

        // Iterate through the linked list
        while (fast && fast->next) {
            // Move slow pointer one step ahead
            slow = slow->next;
            // Move fast pointer two steps ahead
            fast = fast->next->next;

            // If slow and fast pointers meet, there is a cycle
            if (slow == fast)
                return true;
        }
        // If fast pointer reaches the end of the list, there is no cycle
        return false;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/