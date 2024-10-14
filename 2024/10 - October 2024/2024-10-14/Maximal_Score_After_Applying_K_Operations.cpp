class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // 1. Create a priority queue to store elements in descending order
        priority_queue<int> pq(nums.begin(), nums.end(), greater<int>()); // max-heap

        long long score = 0; // Initialize score to store the sum

        // 2. Iterate k times to process the top k elements
        for (int i = 0; i < k; i++) {
            // 3. Extract the maximum element from the priority queue
            int x = pq.top();
            pq.pop();

            // 4. Add the current element to the score
            score += x;

            // 5. Special case: If the element is 1, add remaining k-1-i elements to the score
            //    as their contribution will always be 1 (since (1 + 2) / 3 = 1).
            if (x == 1) {
                score += (k - 1 - i); // Add remaining elements as 1s
                break; // No need to process further since all remaining elements will be 1
            }

            // 6. Divide the element by 3 (rounded down) and push it back to the queue
            //    to potentially contribute to the score again in the next iterations.
            pq.push((x + 2) / 3); // Integer division floors the result
        }

        // 7. Return the final score
        return score;
    }
};

// Time Complexity: O(k * log(n))
// Space Complexity: O(n)
