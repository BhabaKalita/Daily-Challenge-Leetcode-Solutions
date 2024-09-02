class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totChalkNeed = 0; // Calculate the total amount of chalk needed

        // Iterate through the chalk array and accumulate the total
        for (int x : chalk) {
            totChalkNeed += x;
        }

        // Calculate the remaining chalk needed after full rotations
        int rem = k % totChalkNeed;

        // Iterate through the chalk array to find the student who will finish the last chalk
        for (int i = 0; i < chalk.size(); i++) {
            if (rem < chalk[i]) {
                return i; // Return the index of the student who finishes the last chalk
            }

            rem -= chalk[i]; // Subtract the current chalk amount from the remaining chalk
        }

        // If the loop completes without finding a student, it means the first student will finish the last chalk
        return 0;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)
