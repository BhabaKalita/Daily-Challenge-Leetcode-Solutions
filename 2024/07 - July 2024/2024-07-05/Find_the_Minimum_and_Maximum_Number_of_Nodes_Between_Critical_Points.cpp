class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Initialize result vector with -1, indicating no critical points found yet
        vector<int> res(2, -1);
        // Index of the previous critical point
        int prev_critical_ind = -1;
        // Index of the first critical point
        int first_critical_ind = -1;
        // Pointers to traverse the linked list
        ListNode* prev = head;
        ListNode* cur = head->next;
        // Index of the current node
        int cur_ind = 1;

        // Traverse the list until the end
        while (cur->next != nullptr) {
            // Check if the current node is a critical point
            if ((cur->val > prev->val && cur->val > cur->next->val) ||
                (cur->val < prev->val && cur->val < cur->next->val)) {
                // If there was a previous critical point, calculate the distance
                if (prev_critical_ind != -1) {
                    res[0] = (res[0] == -1) ? cur_ind - prev_critical_ind : min(res[0], cur_ind - prev_critical_ind);
                } else {
                    // Otherwise, set the first critical point index
                    first_critical_ind = cur_ind;
                }
                // Update the previous critical point index
                prev_critical_ind = cur_ind;
            }
            // Move to the next node
            prev = cur;
            cur = cur->next;
            cur_ind++;
        }

        // If there are at least two critical points, calculate the maximum distance
        if (prev_critical_ind != -1 && prev_critical_ind != first_critical_ind) {
            res[1] = prev_critical_ind - first_critical_ind;
        }

        return res;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)