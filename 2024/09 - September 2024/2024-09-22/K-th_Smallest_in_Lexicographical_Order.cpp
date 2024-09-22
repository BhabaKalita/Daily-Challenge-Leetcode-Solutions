#include <iostream>
using namespace std;

class Solution {
public:
    // Function to count how many numbers lie between 'prefix' and 'prefix + 1'
    int countSteps(int n, long long prefix, long long nextPrefix) {
        int steps = 0;
        while (prefix <= n) {
            steps += min(n + 1LL, nextPrefix) - prefix;
            prefix *= 10;
            nextPrefix *= 10;
        }
        return steps;
    }

    // Function to find the k-th lexicographically smallest number
    int findKthNumber(int n, int k) {
        long long cur = 1; // Start at the first lexicographical number (1)
        k--; // Decrease k by 1 since we start from 1 already

        while (k > 0) {
            // Count how many numbers lie between 'cur' and 'cur + 1' in the lexicographical tree
            int steps = countSteps(n, cur, cur + 1);
            
            // If k is larger than or equal to the step count, we can skip this prefix
            if (steps <= k) {
                cur++;  // Move to the next sibling (e.g., 1 -> 2)
                k -= steps;  // Reduce k by the number of steps we just skipped
            } else {
                // If k is smaller, we need to go deeper into the current prefix (e.g., 1 -> 10)
                cur *= 10;
                k--;  // Reduce k by 1 as we move one step deeper
            }
        }

        return cur;
    }
};
/*
  Time Complexity : O(Log(N)+K)
  Space Complexity : O(1)
*/
