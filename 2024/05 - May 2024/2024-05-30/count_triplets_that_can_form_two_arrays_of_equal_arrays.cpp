class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();           // Get the size of the array
        int res = 0;                // Initialize the result count
        int prefix = 0;             // Initialize the prefix XOR
        unordered_map<int, int> count = {{0, 1}}; // Map to store the count of prefix XORs
        unordered_map<int, int> total;            // Map to store the total index sum of prefix XORs

        // Iterate over the array
        for (int i = 0; i < n; ++i) {
            prefix ^= A[i];  // Update the prefix XOR with the current element

            // Add to result the count of current prefix XOR seen before times current index,
            // subtract the sum of indices where this prefix XOR was seen before
            res += count[prefix]++ * i - total[prefix];

            // Update the total index sum for the current prefix XOR
            total[prefix] += i + 1;
        }

        return res;  // Return the total count of triplets
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/