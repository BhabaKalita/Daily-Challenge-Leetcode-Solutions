long long countSubarrays(vector<int>& A, int minK, int maxK) {
    // Initialize variables
    long res = 0; // Variable to store the result
    long jbad = -1; // Index of the last element that's out of range [minK, maxK]
    long jmin = -1; // Index of the last occurrence of minK
    long jmax = -1; // Index of the last occurrence of maxK
    long n = A.size(); // Size of the input vector

    // Iterate through the elements of the vector
    for (int i = 0; i < n; ++i) {
        // Check if the current element is less than minK or greater than maxK
        if (A[i] < minK || A[i] > maxK) {
            jbad = i; // Update jbad to mark the index of the current element
        }
        // Check if the current element is equal to minK
        if (A[i] == minK) {
            jmin = i; // Update jmin to mark the index of the current element
        }
        // Check if the current element is equal to maxK
        if (A[i] == maxK) {
            jmax = i; // Update jmax to mark the index of the current element
        }
        // Calculate the number of subarrays ending at the current index
        // where the minimum value is at least minK and the maximum value is at most maxK
        res += max(0L, min(jmin, jmax) - jbad);
    }
    // Return the result
    return res;
}

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/