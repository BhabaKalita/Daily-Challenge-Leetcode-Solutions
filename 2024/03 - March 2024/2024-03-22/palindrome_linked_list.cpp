#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Initialize two pointers for traversing the linked list
        ListNode* slow = head;  // Pointer moves one step at a time
        ListNode* fast = head;  // Pointer moves two steps at a time

        // Find the middle of the linked list using slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        ListNode* prev = nullptr;  // Pointer to the previous node
        ListNode* curr = slow;      // Pointer to the current node

        while (curr != nullptr) {
            ListNode* forward = curr->next;  // Temporary pointer to the next node
            curr->next = prev;               // Reverse the pointer
            prev = curr;                     // Move prev pointer one step forward
            curr = forward;                  // Move curr pointer one step forward
        }

        // Compare the first and second half of the linked list
        ListNode* first = head;   // Pointer to the start of the first half
        ListNode* second = prev;  // Pointer to the start of the reversed second half

        while (second != nullptr) {
            if (first->val != second->val)
                return false;  // If values don't match, it's not a palindrome

            first = first->next;
            second = second->next;
        }
        return true;  // If all values match, it's a palindrome
    }
};

// Time Complexity: O(N) where N is the number of nodes in the linked list.
// We traverse the linked list twice: once to find the middle and once to reverse the second half.
// Space Complexity: O(1) - We are using only a constant amount of extra space, regardless of the size of the input linked list.
