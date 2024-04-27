class Solution {
public:
    using VI = vector<int>; // Alias for vector<int>

    // Function to find the minimum number of steps to spell out the key on the ring
    int findRotateSteps(string ring, string key, int INF = 1e9 + 7) {
        int M = ring.size(); // Length of the ring
        int N = key.size();  // Length of the key

        // Lambda function to calculate the steps to rotate from i to k
        auto steps = [=](auto i, auto k) {
            return min(abs(i - k), M - abs(i - k));
        };

        // Vector to store memoization values, initialized with INF
        VI pre(M);

        // Looping through the key characters in reverse order
        for (auto j{ N - 1 }; 0 <= j; --j) {
            // Vector to store current minimum steps
            VI cur(M, INF);

            // Looping through the characters of the ring
            for (auto i{ 0 }; i < M; ++i) {
                // Looping through the characters of the previous state
                for (auto k{ 0 }; k < M; ++k) {
                    // If the character in the ring matches the current character in the key
                    if (ring[k] == key[j]) {
                        // Update the current minimum steps
                        cur[i] = min(cur[i], 1 + steps(i, k) + pre[k]);
                    }
                }
            }

            // Update the previous state with the current state
            swap(pre, cur);
        }

        // Return the minimum steps required to spell out the key starting from index 0
        return pre[0];
    }
};

/*
Time Complexity: O(M * N ^ 2)
Space Complexity: O(M)
*/