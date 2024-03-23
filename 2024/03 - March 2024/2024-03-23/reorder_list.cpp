#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // Base case: linked list is empty
        if (!head) return;

        // Finding the middle with the help of two-pointer approach
        ListNode *tmp = head, *half = head, *prev = NULL;
        while (tmp->next && tmp->next->next) {
            tmp = tmp->next->next;
            half = half->next;
        }

        // Adding one bit in case of lists with even length
        if (tmp->next) half = half->next;

        // Now reverse the second half
        while (half) {
            tmp = half->next;
            half->next = prev;
            prev = half;
            half = tmp;
        }
        half = prev;

        // After reversing the second half, let's merge both the halves
        while (head && half) {
            tmp = head->next;
            prev = half->next;
            head->next = half;
            half->next = tmp;
            head = tmp;
            half = prev;
        }

        // Base case: closing when we had even length arrays
        if (head && head->next) head->next->next = NULL;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Space Complexity: O(1) as only constant extra space is used.
