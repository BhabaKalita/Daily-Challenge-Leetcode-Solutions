class Solution {
public:
    int nthUglyNumber(int n) {
        // Create a vector `t` of size `n+1` to store the first `n` ugly numbers.
        vector<int> t(n+1);

        // Initialize pointers for multiples of 2, 3, and 5.
        int i2, i3, i5;

        // All pointers start at 1 because the first ugly number is 1.
        i2 = i3 = i5 = 1;

        // The first ugly number is always 1.
        t[1] = 1;

        // Iterate from 2 to `n` to find the `nth` ugly number.
        for(int i = 2; i <= n; i++) {

            // Calculate the next possible ugly number from each pointer.
            int i2_th = t[i2] * 2;
            int i3_th = t[i3] * 3;
            int i5_th = t[i5] * 5;

            // The next ugly number is the smallest of these candidates.
            t[i] = min({i2_th, i3_th, i5_th});

            // Move the pointer that matched the selected ugly number.
            if(t[i] == i2_th)
                i2++;

            if(t[i] == i3_th)
                i3++;

            if(t[i] == i5_th)
                i5++;
        }

        // Return the `nth` ugly number.
        return t[n];
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)