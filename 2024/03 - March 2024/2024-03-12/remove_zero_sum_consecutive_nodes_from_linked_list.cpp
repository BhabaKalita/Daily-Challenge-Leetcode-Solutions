// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeZeroSumSublists(ListNode* head) {
    // Create a dummy node to handle edge cases
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    dummy->next = head;

    // Initialize a prefix sum and a map to store prefix sums and their corresponding node pointers
    int prefix = 0;
    map<int, ListNode*> m;

    // Iterate through the list
    while (cur) {
        prefix += cur->val; // Update prefix sum

        // If the current prefix sum is already in the map, remove the sublist from the last occurrence of the prefix sum
        if (m.count(prefix)) {
            cur =  m[prefix]->next;
            int p = prefix + cur->val;
            while (p != prefix) {
                m.erase(p);
                cur = cur->next;
                p += cur->val;
            }
            m[prefix]->next = cur->next;
        } else { // If the prefix sum is not in the map, add it to the map
            m[prefix] = cur;
        }
        cur = cur->next;
    }

    return dummy->next; // Return the head of the modified list
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/