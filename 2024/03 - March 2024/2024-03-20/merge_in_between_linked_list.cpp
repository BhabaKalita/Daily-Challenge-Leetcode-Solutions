class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Initialize jump1 to count nodes until reaching index a
        int jump1 = 1;
        ListNode *temp1 = list1;
        while (jump1 < a) { // Traverse list1 until reaching index a
            temp1 = temp1->next; // Move to the next node
            jump1++; // Increment jump1
        }

        // Initialize jump2 to count nodes until reaching index b
        int jump2 = 1;
        ListNode *temp2 = list1;
        while(jump2 <= b) { // Traverse list1 until reaching index b
            temp2 = temp2->next; // Move to the next node
            jump2++; // Increment jump2
        }

        // Traverse list2 to find its last node
        ListNode *temp3 = list2;
        while(temp3->next != NULL) {
            temp3 = temp3->next; // Move to the next node
        }

        // Link the node after a to the head of list2
        temp1->next = list2;

        // Link the last node of list2 to the node after b
        temp3->next = temp2->next;

        // Return the modified list1
        return list1;
    }
};
// Time Complexity: O(a+b+N)
// Space Complexity: O(1)