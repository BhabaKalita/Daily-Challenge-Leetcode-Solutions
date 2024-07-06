class Solution {
public:
    int passThePillow(int n, int time) {
        // Calculate the number of complete rounds of passing the pillow (chunks)
        int chunks = time / (n-1);

        // If the number of complete rounds is even, the pillow is moving forward
        // If the number of complete rounds is odd, the pillow is moving backward
        return chunks % 2 == 0 ? (time % (n-1) + 1) : (n - time % (n-1));
    }
};
// Time Complexity: O(1)
// Space Complexity: O(1)