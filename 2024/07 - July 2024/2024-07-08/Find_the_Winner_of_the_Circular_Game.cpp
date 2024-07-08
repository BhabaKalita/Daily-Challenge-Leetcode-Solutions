class Solution {
public:
    // Helper function to solve the Josephus problem.
    // n: number of people in the circle
    // k: step rate (every k-th person is eliminated)
    int solve(int n, int k) {
        // Base case: if there's only one person, they are the winner
        if(n == 1)
            return 0;
        // Recursive step: adjust the winner's position in the reduced problem
        // solve(n-1, k) gives the winner's position in a circle of n-1 people
        // we add k (the step) and take modulo n to wrap around the circle
        return (solve(n-1, k) + k) % n;
    }

    // Public method to find the winner of the Josephus problem.
    // n: number of people in the circle
    // k: step rate (every k-th person is eliminated)
    int findTheWinner(int n, int k) {
        // The winner's position is adjusted to be 1-indexed
        return solve(n, k) + 1;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)